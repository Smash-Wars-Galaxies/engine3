/*
** Copyright (C) 2007-2019 SWGEmu
** See file COPYING for copying conditions.
*/

#pragma once

#include "system/lang.h"

#include "engine/core/Core.h"

#include "engine/core/Task.h"
#include "engine/core/TaskManager.h"

#include "engine/core/ManagedReference.h"
#include "engine/core/ManagedWeakReference.h"
#include "engine/core/ManagedObject.h"

//#include "engine/core/util/ManagedVector.h"
//#include "engine/core/util/ManagedVectorImplementation.h"
#include "engine/core/util/ManagedSortedVector.h"
#include "engine/core/util/ManagedVectorMap.h"

#include "engine/log/Logger.h"

#include "engine/service/ServiceException.h"
#include "engine/service/ServiceClient.h"
#include "engine/service/ServiceClientMap.h"
#include "engine/service/DatagramServiceClient.h"
#include "engine/service/DatagramServiceClientProxy.h"
#include "engine/service/DatagramServiceThread.h"
#include "engine/service/DatagramServiceThread.h"
#include "engine/service/StreamServiceClient.h"
#include "engine/service/StreamServiceClientProxy.h"
#include "engine/service/StreamServiceThread.h"

#include "engine/service/Message.h"

#include "engine/service/proto/BaseClient.h"
#include "engine/service/proto/BaseClientProxy.h"
#include "engine/service/proto/BasePacket.h"
#include "engine/service/proto/BasePacketHandler.h"
#include "engine/service/proto/BaseMessage.h"
#include "engine/service/proto/StandaloneBaseMessage.h"

#include "engine/service/proto/packets/PingMessage.h"
#include "engine/service/proto/packets/NetStatusResponseMessage.h"
#include "engine/service/proto/packets/NetStatusRequestMessage.h"
#include "engine/service/proto/packets/AcknowledgeMessage.h"
#include "engine/service/proto/packets/AcknowledgeOkMessage.h"
#include "engine/service/proto/packets/ConnectionServerMessage.h"
#include "engine/service/proto/packets/LoginServerMessage.h"

#include "engine/orb/DistributedObjectBroker.h"
#include "engine/orb/db/DOBObjectManager.h"

#include "engine/stm/TransactionalMemoryManager.h"

#include "engine/db/Database.h"
#include "engine/db/ObjectDatabase.h"
#include "engine/db/ObjectDatabaseManager.h"
#include "engine/db/BinaryData.h"
#include "engine/db/berkeley/BerkeleyDatabase.h"

#include "engine/lua/Lua.h"

#include "engine/util/u3d/Quaternion.h"
#include "engine/util/u3d/Vector3.h"
#include "engine/util/u3d/AABBTree.h"
#include "engine/util/u3d/AStarAlgorithm.h"
#include "engine/util/u3d/TriangulationAStarAlgorithm.h"
#include "engine/util/u3d/Funnel.h"
#include "engine/util/iffstream/IffStream.h"

