/*
** Copyright (C) 2007-2019 SWGEmu
** See file COPYING for copying conditions.
*/

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/orb/db/DOBObjectManager.h"

#include "engine/orb/messages/DeployObjectMessage.h"
#include "engine/orb/messages/InvokeMethodMessage.h"
#include "engine/orb/messages/LookUpObjectMessage.h"
#include "engine/orb/messages/LookUpObjectByIDMessage.h"
#include "engine/orb/messages/LoadPersistentObjectMessage.h"
#include "engine/orb/messages/UpdatePersistentObjectMessage.h"
#include "engine/orb/messages/GetNextFreeObjectIDMessage.h"
#include "engine/orb/messages/UndeployObjectMessage.h"
#include "engine/orb/messages/RequestServantMessage.h"
#include "engine/orb/messages/SendObjectDataMessage.h"

#include "engine/orb/control/ControlMessage.h"
#include "engine/orb/control/StateUpdateMessage.h"

#include "engine/orb/messages/DOBMessageFactory.h"

DOBMessageFactory::DOBMessageFactory() {
}

class ControlMessageProcessorTask : public Task {
	DOBMessage* message;

public:
	ControlMessageProcessorTask(DOBMessage* msg) {
		message = msg;
	}

	void run() {
		message->execute();
	}
};

void DOBMessageFactory::process(DOBServiceClient* client, Packet* message) {
	//printf("received dob message:%s\n", message->toStringData().toCharArray());

	try {
		DistributedObjectBroker* broker = DistributedObjectBroker::instance();

		uint32 messageType = message->parseInt();

		//printf("messageType: %d\n", messageType);

		if (messageType != DOBMessage::REPLYMESSAGE) {
			DOBMessage* dobMessage = create(messageType, message);
			broker->fatal(dobMessage != nullptr) << "dobMessage is null";

			dobMessage->setClient(client);

			broker->debug() << "DOBMessage(" << dobMessage->getSequence() << "): " << messageType
							<< " arrived with content: " << message->toStringData();

			if (messageType == DOBMessage::CONTROLMESSAGE) {
				Task* task = new ControlMessageProcessorTask(dobMessage);
				task->execute();
			} else {
				try {
					dobMessage->execute();
				} catch (Exception& e){
					broker->error(e.getMessage());
					e.printStackTrace();
				}
			}
		} else {
			DOBMessage* queuedMessage = client->getQueuedMessage(message->parseInt());

			broker->debug() << "DOBMessage(" << queuedMessage->getSequence() << "): "
							<< "reply arrived with content: " << message->toStringData();

			queuedMessage->handleReply(message);

			queuedMessage->signalReply();
		}

	} catch (const StreamIndexOutOfBoundsException& e) {
		e.printStackTrace();

		System::out << e.getStream()->toStringData() << endl;
	} catch (const Exception& e) {
		e.printStackTrace();
	}
}

DOBMessage* DOBMessageFactory::create(uint32 messageType, Packet* message) {
	switch (messageType) {
	case DOBMessage::LOOKUPOBJECTMESSAGE:
		return new LookUpObjectMessage(message);

	case DOBMessage::LOOKUPOBJECTBYIDMESSAGE:
		return new LookUpObjectByIDMessage(message);

	case DOBMessage::DEPLOYOBJECTMESSAGE:
		return new DeployObjectMessage(message);

	case DOBMessage::UNDEPLOYOBJECTMESSAGE:
		return new UndeployObjectMessage(message);

	case DOBMessage::INVOKEMETHODMESSAGE:
		return new InvokeMethodMessage(message);

	case DOBMessage::LOADPERSISTENTOBJECTMESSAGE:
		return new LoadPersistentObjectMessage(message);

	case DOBMessage::UPDATEPERSISTENTOBJECTMESSAGE:
		return new UpdatePersistentObjectMessage(message);

	case DOBMessage::GETNEXTFREEOBJECTIDMESSAGE:
		return new GetNextFreeObjectIDMessage(message);

	case DOBMessage::CONTROLMESSAGE:
		return new ControlMessage(message);

	case DOBMessage::STATEUPDATEMESSAGE:
		return new StateUpdateMessage(message);

	case DOBMessage::REQUESTSERVANT:
		return new RequestServantMessage(message);

	case DOBMessage::SENDOBJECTDATA:
		return new SendObjectDataMessage(message);

	default:
		return nullptr;
	}
}
