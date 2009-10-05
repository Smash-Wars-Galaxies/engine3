/*
 * ObjectUpdateToDatabaseTask.cpp
 *
 *  Created on: 05/10/2009
 *      Author: victor
 */

#include "ObjectUpdateToDatabaseTask.h"
#include "ManagedObject.h"
#include "ManagedReference.h"

ObjectUpdateToDatabaseTask::ObjectUpdateToDatabaseTask(ManagedObject* object) : Task(300000) {
	ObjectUpdateToDatabaseTask::object = object;
}

void ObjectUpdateToDatabaseTask::run() {
	try {
		object->wlock();

		object->clearUpdateToDatabaseTask();
		object->updateToDatabase();

		object->unlock();
	} catch (Exception& e) {
		//object->error(e.getMessage());
		object->unlock();
	} catch (...) {
		//object->error("unreported exception caught in ObjectSaveToDatabaseTask::run");
		object->unlock();
	}
}
