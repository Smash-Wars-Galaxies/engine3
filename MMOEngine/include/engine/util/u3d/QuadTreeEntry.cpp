/*
 *	engine/util/u3d/QuadTreeEntry.cpp generated by engine3 IDL compiler 0.60
 */

#include "QuadTreeEntry.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/u3d/Vector3.h"

#include "engine/util/u3d/QuadTree.h"

#include "engine/util/u3d/QuadTreeNode.h"

/*
 *	QuadTreeEntryStub
 */

QuadTreeEntry::QuadTreeEntry(QuadTreeNode* n) : Observable(DummyConstructorParameter::instance()) {
	QuadTreeEntryImplementation* _implementation = new QuadTreeEntryImplementation(n);
	_impl = _implementation;
	_impl->_setStub(this);
}

QuadTreeEntry::QuadTreeEntry(DummyConstructorParameter* param) : Observable(param) {
}

QuadTreeEntry::~QuadTreeEntry() {
}


void QuadTreeEntry::notifyAddedToCloseObjects() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyAddedToCloseObjects();
}

void QuadTreeEntry::notifyRemovedFromCloseObjects() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyRemovedFromCloseObjects();
}

void QuadTreeEntry::addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(obj);
		method.addBooleanParameter(doNotifyUpdate);

		method.executeWithVoidReturn();
	} else
		_implementation->addInRangeObject(obj, doNotifyUpdate);
}

QuadTreeEntry* QuadTreeEntry::getInRangeObject(int index) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addSignedIntParameter(index);

		return (QuadTreeEntry*) method.executeWithObjectReturn();
	} else
		return _implementation->getInRangeObject(index);
}

void QuadTreeEntry::removeInRangeObject(QuadTreeEntry* obj) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->removeInRangeObject(obj);
}

void QuadTreeEntry::removeInRangeObject(int index) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addSignedIntParameter(index);

		method.executeWithVoidReturn();
	} else
		_implementation->removeInRangeObject(index);
}

void QuadTreeEntry::removeInRangeObjects() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		method.executeWithVoidReturn();
	} else
		_implementation->removeInRangeObjects();
}

bool QuadTreeEntry::containsInRangeObject(QuadTreeEntry* obj) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(obj);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->containsInRangeObject(obj);
}

bool QuadTreeEntry::isInRange(QuadTreeEntry* obj, float range) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addObjectParameter(obj);
		method.addFloatParameter(range);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isInRange(obj, range);
}

bool QuadTreeEntry::isInRange(float x, float y, float range) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addFloatParameter(range);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isInRange(x, y, range);
}

float QuadTreeEntry::getDistanceTo(QuadTreeEntry* obj) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addObjectParameter(obj);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getDistanceTo(obj);
}

bool QuadTreeEntry::isInSWArea(QuadTreeNode* node) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->isInSWArea(node);
}

bool QuadTreeEntry::isInSEArea(QuadTreeNode* node) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->isInSEArea(node);
}

bool QuadTreeEntry::isInNWArea(QuadTreeNode* node) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->isInNWArea(node);
}

bool QuadTreeEntry::isInArea(QuadTreeNode* node) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->isInArea(node);
}

void QuadTreeEntry::notifyInsert(QuadTreeEntry* obj) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyInsert(obj);
}

void QuadTreeEntry::notifyPositionUpdate(QuadTreeEntry* obj) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyPositionUpdate(obj);
}

void QuadTreeEntry::notifyDissapear(QuadTreeEntry* obj) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyDissapear(obj);
}

float QuadTreeEntry::getPositionX() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getPositionX();
}

float QuadTreeEntry::getPositionZ() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getPositionZ();
}

float QuadTreeEntry::getPositionY() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getPositionY();
}

float QuadTreeEntry::getPreviousPositionX() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getPreviousPositionX();
}

float QuadTreeEntry::getPreviousPositionZ() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getPreviousPositionZ();
}

float QuadTreeEntry::getPreviousPositionY() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getPreviousPositionY();
}

Vector3 QuadTreeEntry::getPosition() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getPosition();
}

void QuadTreeEntry::setPosition(float x, float z, float y) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addFloatParameter(x);
		method.addFloatParameter(z);
		method.addFloatParameter(y);

		method.executeWithVoidReturn();
	} else
		_implementation->setPosition(x, z, y);
}

void QuadTreeEntry::initializePosition(float x, float z, float y) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addFloatParameter(x);
		method.addFloatParameter(z);
		method.addFloatParameter(y);

		method.executeWithVoidReturn();
	} else
		_implementation->initializePosition(x, z, y);
}

int QuadTreeEntry::compareTo(QuadTreeEntry* obj) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addObjectParameter(obj);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->compareTo(obj);
}

bool QuadTreeEntry::isInQuadTree() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isInQuadTree();
}

int QuadTreeEntry::inRangeObjectCount() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->inRangeObjectCount();
}

QuadTreeNode* QuadTreeEntry::getNode() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getNode();
}

unsigned long long QuadTreeEntry::getObjectID() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getObjectID();
}

float QuadTreeEntry::getRadius() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getRadius();
}

bool QuadTreeEntry::isBounding() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isBounding();
}

void QuadTreeEntry::setNode(QuadTreeNode* n) {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->setNode(n);
}

void QuadTreeEntry::setBounding() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);

		method.executeWithVoidReturn();
	} else
		_implementation->setBounding();
}

void QuadTreeEntry::clearBounding() {
	QuadTreeEntryImplementation* _implementation = (QuadTreeEntryImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);

		method.executeWithVoidReturn();
	} else
		_implementation->clearBounding();
}

DistributedObjectServant* QuadTreeEntry::_getImplementation() {

	_updated = true;
	return _impl;
}

void QuadTreeEntry::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	QuadTreeEntryImplementation
 */

QuadTreeEntryImplementation::QuadTreeEntryImplementation(DummyConstructorParameter* param) : ObservableImplementation(param) {
	_initializeImplementation();
}


QuadTreeEntryImplementation::~QuadTreeEntryImplementation() {
}


void QuadTreeEntryImplementation::finalize() {
}

void QuadTreeEntryImplementation::_initializeImplementation() {
	_setClassHelper(QuadTreeEntryHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void QuadTreeEntryImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (QuadTreeEntry*) stub;
	ObservableImplementation::_setStub(stub);
}

DistributedObjectStub* QuadTreeEntryImplementation::_getStub() {
	return _this;
}

QuadTreeEntryImplementation::operator const QuadTreeEntry*() {
	return _this;
}

void QuadTreeEntryImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void QuadTreeEntryImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void QuadTreeEntryImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void QuadTreeEntryImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void QuadTreeEntryImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void QuadTreeEntryImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void QuadTreeEntryImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void QuadTreeEntryImplementation::_serializationHelperMethod() {
	ObservableImplementation::_serializationHelperMethod();

	_setClassName("QuadTreeEntry");

}

void QuadTreeEntryImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(QuadTreeEntryImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool QuadTreeEntryImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ObservableImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "bounding") {
		TypeInfo<bool >::parseFromBinaryStream(&bounding, stream);
		return true;
	}

	if (_name == "positionX") {
		TypeInfo<float >::parseFromBinaryStream(&positionX, stream);
		return true;
	}

	if (_name == "positionY") {
		TypeInfo<float >::parseFromBinaryStream(&positionY, stream);
		return true;
	}

	if (_name == "positionZ") {
		TypeInfo<float >::parseFromBinaryStream(&positionZ, stream);
		return true;
	}

	if (_name == "radius") {
		TypeInfo<float >::parseFromBinaryStream(&radius, stream);
		return true;
	}


	return false;
}

void QuadTreeEntryImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = QuadTreeEntryImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int QuadTreeEntryImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "bounding";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<bool >::toBinaryStream(&bounding, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "positionX";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&positionX, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "positionY";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&positionY, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "positionZ";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&positionZ, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "radius";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&radius, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 5 + ObservableImplementation::writeObjectMembers(stream);
}

void QuadTreeEntryImplementation::notifyAddedToCloseObjects() {
}

void QuadTreeEntryImplementation::notifyRemovedFromCloseObjects() {
}

void QuadTreeEntryImplementation::addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate) {
	// engine/util/u3d/QuadTreeEntry.idl():  	}
	if ((&closeobjects)->put(obj) != -1){
	// engine/util/u3d/QuadTreeEntry.idl():  			notifyInsert(obj);
	notifyInsert(obj);
	// engine/util/u3d/QuadTreeEntry.idl():  			obj.notifyAddedToCloseObjects();
	obj->notifyAddedToCloseObjects();
}

	else 	// engine/util/u3d/QuadTreeEntry.idl():  	}
	if (doNotifyUpdate){
	// engine/util/u3d/QuadTreeEntry.idl():  			notifyPositionUpdate(obj);
	notifyPositionUpdate(obj);
}
}

QuadTreeEntry* QuadTreeEntryImplementation::getInRangeObject(int index) {
	// engine/util/u3d/QuadTreeEntry.idl():  		return closeobjects.get(index);
	return (&closeobjects)->get(index);
}

void QuadTreeEntryImplementation::removeInRangeObject(QuadTreeEntry* obj) {
	// engine/util/u3d/QuadTreeEntry.idl():  	}
	if ((&closeobjects)->drop(obj)){
	// engine/util/u3d/QuadTreeEntry.idl():  			notifyDissapear(obj);
	notifyDissapear(obj);
	// engine/util/u3d/QuadTreeEntry.idl():  			obj.notifyRemovedFromCloseObjects();
	obj->notifyRemovedFromCloseObjects();
}
}

void QuadTreeEntryImplementation::removeInRangeObject(int index) {
	// engine/util/u3d/QuadTreeEntry.idl():  		QuadTreeEntry entry = closeobjects.remove(index);
	QuadTreeEntry* entry = (&closeobjects)->remove(index);
	// engine/util/u3d/QuadTreeEntry.idl():  		entry.notifyRemovedFromCloseObjects();
	entry->notifyRemovedFromCloseObjects();
}

void QuadTreeEntryImplementation::removeInRangeObjects() {
	// engine/util/u3d/QuadTreeEntry.idl():  		}
	for (	// engine/util/u3d/QuadTreeEntry.idl():  		for (int i = 0;
	int i = 0;
	i < (&closeobjects)->size();
 ++i) {
	// engine/util/u3d/QuadTreeEntry.idl():  			closeobjects.get(i).notifyRemovedFromCloseObjects();
	(&closeobjects)->get(i)->notifyRemovedFromCloseObjects();
}
	// engine/util/u3d/QuadTreeEntry.idl():  		closeobjects.removeAll();
	(&closeobjects)->removeAll();
}

bool QuadTreeEntryImplementation::containsInRangeObject(QuadTreeEntry* obj) {
	// engine/util/u3d/QuadTreeEntry.idl():  		return closeobjects.contains(obj);
	return (&closeobjects)->contains(obj);
}

bool QuadTreeEntryImplementation::isInRange(QuadTreeEntry* obj, float range) {
	// engine/util/u3d/QuadTreeEntry.idl():  		return isInRange(obj.getPositionX(), obj.getPositionY(), range);
	return isInRange(obj->getPositionX(), obj->getPositionY(), range);
}

bool QuadTreeEntryImplementation::isInRange(float x, float y, float range) {
	// engine/util/u3d/QuadTreeEntry.idl():  	 	float rangesq = range * range;
	float rangesq = range * range;
	// engine/util/u3d/QuadTreeEntry.idl():  		float deltaX = x - positionX;
	float deltaX = x - positionX;
	// engine/util/u3d/QuadTreeEntry.idl():  		float deltaY = y - positionY;
	float deltaY = y - positionY;
	// engine/util/u3d/QuadTreeEntry.idl():  			return false;
	if (deltaX * deltaX + deltaY * deltaY <= rangesq)	// engine/util/u3d/QuadTreeEntry.idl():  			return true;
	return true;

	else 	// engine/util/u3d/QuadTreeEntry.idl():  			return false;
	return false;
}

float QuadTreeEntryImplementation::getDistanceTo(QuadTreeEntry* obj) {
	// engine/util/u3d/QuadTreeEntry.idl():  		float x = obj.getPositionX();
	float x = obj->getPositionX();
	// engine/util/u3d/QuadTreeEntry.idl():  		float y = obj.getPositionY();
	float y = obj->getPositionY();
	// engine/util/u3d/QuadTreeEntry.idl():  		float deltaX = x - positionX;
	float deltaX = x - positionX;
	// engine/util/u3d/QuadTreeEntry.idl():  		float deltaY = y - positionY;
	float deltaY = y - positionY;
	// engine/util/u3d/QuadTreeEntry.idl():  		return Math.sqrt(deltaX * deltaX + deltaY * deltaY);
	return Math::sqrt(deltaX * deltaX + deltaY * deltaY);
}

void QuadTreeEntryImplementation::notifyInsert(QuadTreeEntry* obj) {
}

void QuadTreeEntryImplementation::notifyPositionUpdate(QuadTreeEntry* obj) {
}

void QuadTreeEntryImplementation::notifyDissapear(QuadTreeEntry* obj) {
}

float QuadTreeEntryImplementation::getPositionX() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return Coordinate.getPositionX();
	return Coordinate::getPositionX();
}

float QuadTreeEntryImplementation::getPositionZ() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return Coordinate.getPositionZ();
	return Coordinate::getPositionZ();
}

float QuadTreeEntryImplementation::getPositionY() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return Coordinate.getPositionY();
	return Coordinate::getPositionY();
}

float QuadTreeEntryImplementation::getPreviousPositionX() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return Coordinate.getPreviousPositionX();
	return Coordinate::getPreviousPositionX();
}

float QuadTreeEntryImplementation::getPreviousPositionZ() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return Coordinate.getPreviousPositionZ();
	return Coordinate::getPreviousPositionZ();
}

float QuadTreeEntryImplementation::getPreviousPositionY() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return Coordinate.getPreviousPositionY();
	return Coordinate::getPreviousPositionY();
}

Vector3 QuadTreeEntryImplementation::getPosition() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return Coordinate.getPosition();
	return Coordinate::getPosition();
}

void QuadTreeEntryImplementation::setPosition(float x, float z, float y) {
	// engine/util/u3d/QuadTreeEntry.idl():  		Coordinate.setPosition(x, z, y);
	Coordinate::setPosition(x, z, y);
}

void QuadTreeEntryImplementation::initializePosition(float x, float z, float y) {
	// engine/util/u3d/QuadTreeEntry.idl():  		Coordinate.initializePosition(x, z, y);
	Coordinate::initializePosition(x, z, y);
}

int QuadTreeEntryImplementation::compareTo(QuadTreeEntry* obj) {
	// engine/util/u3d/QuadTreeEntry.idl():  			return 0;
	if (getObjectID() < obj->getObjectID())	// engine/util/u3d/QuadTreeEntry.idl():  			return 1;
	return 1;

	else 	// engine/util/u3d/QuadTreeEntry.idl():  			return 0;
	if (getObjectID() > obj->getObjectID())	// engine/util/u3d/QuadTreeEntry.idl():  			return -1;
	return -1;

	else 	// engine/util/u3d/QuadTreeEntry.idl():  			return 0;
	return 0;
}

bool QuadTreeEntryImplementation::isInQuadTree() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return node.get() != null;
	return (&node)->get() != NULL;
}

int QuadTreeEntryImplementation::inRangeObjectCount() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return closeobjects.size();
	return (&closeobjects)->size();
}

QuadTreeNode* QuadTreeEntryImplementation::getNode() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return node.get();
	return (&node)->get();
}

unsigned long long QuadTreeEntryImplementation::getObjectID() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return 0;
	return 0;
}

float QuadTreeEntryImplementation::getRadius() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return radius;
	return radius;
}

bool QuadTreeEntryImplementation::isBounding() {
	// engine/util/u3d/QuadTreeEntry.idl():  		return bounding;
	return bounding;
}

void QuadTreeEntryImplementation::setBounding() {
	// engine/util/u3d/QuadTreeEntry.idl():  		bounding = true;
	bounding = true;
}

void QuadTreeEntryImplementation::clearBounding() {
	// engine/util/u3d/QuadTreeEntry.idl():  		bounding = false;
	bounding = false;
}

/*
 *	QuadTreeEntryAdapter
 */

QuadTreeEntryAdapter::QuadTreeEntryAdapter(QuadTreeEntryImplementation* obj) : ObservableAdapter(obj) {
}

enum {RPC_NOTIFYADDEDTOCLOSEOBJECTS__ = 6,RPC_NOTIFYREMOVEDFROMCLOSEOBJECTS__,RPC_ADDINRANGEOBJECT__QUADTREEENTRY_BOOL_,RPC_GETINRANGEOBJECT__INT_,RPC_REMOVEINRANGEOBJECT__QUADTREEENTRY_,RPC_REMOVEINRANGEOBJECT__INT_,RPC_REMOVEINRANGEOBJECTS__,RPC_CONTAINSINRANGEOBJECT__QUADTREEENTRY_,RPC_ISINRANGE__QUADTREEENTRY_FLOAT_,RPC_ISINRANGE__FLOAT_FLOAT_FLOAT_,RPC_GETDISTANCETO__QUADTREEENTRY_,RPC_NOTIFYINSERT__QUADTREEENTRY_,RPC_NOTIFYPOSITIONUPDATE__QUADTREEENTRY_,RPC_NOTIFYDISSAPEAR__QUADTREEENTRY_,RPC_GETPOSITIONX__,RPC_GETPOSITIONZ__,RPC_GETPOSITIONY__,RPC_GETPREVIOUSPOSITIONX__,RPC_GETPREVIOUSPOSITIONZ__,RPC_GETPREVIOUSPOSITIONY__,RPC_SETPOSITION__FLOAT_FLOAT_FLOAT_,RPC_INITIALIZEPOSITION__FLOAT_FLOAT_FLOAT_,RPC_COMPARETO__QUADTREEENTRY_,RPC_ISINQUADTREE__,RPC_INRANGEOBJECTCOUNT__,RPC_GETOBJECTID__,RPC_GETRADIUS__,RPC_ISBOUNDING__,RPC_SETBOUNDING__,RPC_CLEARBOUNDING__};

Packet* QuadTreeEntryAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_NOTIFYADDEDTOCLOSEOBJECTS__:
		notifyAddedToCloseObjects();
		break;
	case RPC_NOTIFYREMOVEDFROMCLOSEOBJECTS__:
		notifyRemovedFromCloseObjects();
		break;
	case RPC_ADDINRANGEOBJECT__QUADTREEENTRY_BOOL_:
		addInRangeObject((QuadTreeEntry*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case RPC_GETINRANGEOBJECT__INT_:
		resp->insertLong(getInRangeObject(inv->getSignedIntParameter())->_getObjectID());
		break;
	case RPC_REMOVEINRANGEOBJECT__QUADTREEENTRY_:
		removeInRangeObject((QuadTreeEntry*) inv->getObjectParameter());
		break;
	case RPC_REMOVEINRANGEOBJECT__INT_:
		removeInRangeObject(inv->getSignedIntParameter());
		break;
	case RPC_REMOVEINRANGEOBJECTS__:
		removeInRangeObjects();
		break;
	case RPC_CONTAINSINRANGEOBJECT__QUADTREEENTRY_:
		resp->insertBoolean(containsInRangeObject((QuadTreeEntry*) inv->getObjectParameter()));
		break;
	case RPC_ISINRANGE__QUADTREEENTRY_FLOAT_:
		resp->insertBoolean(isInRange((QuadTreeEntry*) inv->getObjectParameter(), inv->getFloatParameter()));
		break;
	case RPC_ISINRANGE__FLOAT_FLOAT_FLOAT_:
		resp->insertBoolean(isInRange(inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter()));
		break;
	case RPC_GETDISTANCETO__QUADTREEENTRY_:
		resp->insertFloat(getDistanceTo((QuadTreeEntry*) inv->getObjectParameter()));
		break;
	case RPC_NOTIFYINSERT__QUADTREEENTRY_:
		notifyInsert((QuadTreeEntry*) inv->getObjectParameter());
		break;
	case RPC_NOTIFYPOSITIONUPDATE__QUADTREEENTRY_:
		notifyPositionUpdate((QuadTreeEntry*) inv->getObjectParameter());
		break;
	case RPC_NOTIFYDISSAPEAR__QUADTREEENTRY_:
		notifyDissapear((QuadTreeEntry*) inv->getObjectParameter());
		break;
	case RPC_GETPOSITIONX__:
		resp->insertFloat(getPositionX());
		break;
	case RPC_GETPOSITIONZ__:
		resp->insertFloat(getPositionZ());
		break;
	case RPC_GETPOSITIONY__:
		resp->insertFloat(getPositionY());
		break;
	case RPC_GETPREVIOUSPOSITIONX__:
		resp->insertFloat(getPreviousPositionX());
		break;
	case RPC_GETPREVIOUSPOSITIONZ__:
		resp->insertFloat(getPreviousPositionZ());
		break;
	case RPC_GETPREVIOUSPOSITIONY__:
		resp->insertFloat(getPreviousPositionY());
		break;
	case RPC_SETPOSITION__FLOAT_FLOAT_FLOAT_:
		setPosition(inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter());
		break;
	case RPC_INITIALIZEPOSITION__FLOAT_FLOAT_FLOAT_:
		initializePosition(inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter());
		break;
	case RPC_COMPARETO__QUADTREEENTRY_:
		resp->insertSignedInt(compareTo((QuadTreeEntry*) inv->getObjectParameter()));
		break;
	case RPC_ISINQUADTREE__:
		resp->insertBoolean(isInQuadTree());
		break;
	case RPC_INRANGEOBJECTCOUNT__:
		resp->insertSignedInt(inRangeObjectCount());
		break;
	case RPC_GETOBJECTID__:
		resp->insertLong(getObjectID());
		break;
	case RPC_GETRADIUS__:
		resp->insertFloat(getRadius());
		break;
	case RPC_ISBOUNDING__:
		resp->insertBoolean(isBounding());
		break;
	case RPC_SETBOUNDING__:
		setBounding();
		break;
	case RPC_CLEARBOUNDING__:
		clearBounding();
		break;
	default:
		return NULL;
	}

	return resp;
}

void QuadTreeEntryAdapter::notifyAddedToCloseObjects() {
	((QuadTreeEntryImplementation*) impl)->notifyAddedToCloseObjects();
}

void QuadTreeEntryAdapter::notifyRemovedFromCloseObjects() {
	((QuadTreeEntryImplementation*) impl)->notifyRemovedFromCloseObjects();
}

void QuadTreeEntryAdapter::addInRangeObject(QuadTreeEntry* obj, bool doNotifyUpdate) {
	((QuadTreeEntryImplementation*) impl)->addInRangeObject(obj, doNotifyUpdate);
}

QuadTreeEntry* QuadTreeEntryAdapter::getInRangeObject(int index) {
	return ((QuadTreeEntryImplementation*) impl)->getInRangeObject(index);
}

void QuadTreeEntryAdapter::removeInRangeObject(QuadTreeEntry* obj) {
	((QuadTreeEntryImplementation*) impl)->removeInRangeObject(obj);
}

void QuadTreeEntryAdapter::removeInRangeObject(int index) {
	((QuadTreeEntryImplementation*) impl)->removeInRangeObject(index);
}

void QuadTreeEntryAdapter::removeInRangeObjects() {
	((QuadTreeEntryImplementation*) impl)->removeInRangeObjects();
}

bool QuadTreeEntryAdapter::containsInRangeObject(QuadTreeEntry* obj) {
	return ((QuadTreeEntryImplementation*) impl)->containsInRangeObject(obj);
}

bool QuadTreeEntryAdapter::isInRange(QuadTreeEntry* obj, float range) {
	return ((QuadTreeEntryImplementation*) impl)->isInRange(obj, range);
}

bool QuadTreeEntryAdapter::isInRange(float x, float y, float range) {
	return ((QuadTreeEntryImplementation*) impl)->isInRange(x, y, range);
}

float QuadTreeEntryAdapter::getDistanceTo(QuadTreeEntry* obj) {
	return ((QuadTreeEntryImplementation*) impl)->getDistanceTo(obj);
}

void QuadTreeEntryAdapter::notifyInsert(QuadTreeEntry* obj) {
	((QuadTreeEntryImplementation*) impl)->notifyInsert(obj);
}

void QuadTreeEntryAdapter::notifyPositionUpdate(QuadTreeEntry* obj) {
	((QuadTreeEntryImplementation*) impl)->notifyPositionUpdate(obj);
}

void QuadTreeEntryAdapter::notifyDissapear(QuadTreeEntry* obj) {
	((QuadTreeEntryImplementation*) impl)->notifyDissapear(obj);
}

float QuadTreeEntryAdapter::getPositionX() {
	return ((QuadTreeEntryImplementation*) impl)->getPositionX();
}

float QuadTreeEntryAdapter::getPositionZ() {
	return ((QuadTreeEntryImplementation*) impl)->getPositionZ();
}

float QuadTreeEntryAdapter::getPositionY() {
	return ((QuadTreeEntryImplementation*) impl)->getPositionY();
}

float QuadTreeEntryAdapter::getPreviousPositionX() {
	return ((QuadTreeEntryImplementation*) impl)->getPreviousPositionX();
}

float QuadTreeEntryAdapter::getPreviousPositionZ() {
	return ((QuadTreeEntryImplementation*) impl)->getPreviousPositionZ();
}

float QuadTreeEntryAdapter::getPreviousPositionY() {
	return ((QuadTreeEntryImplementation*) impl)->getPreviousPositionY();
}

void QuadTreeEntryAdapter::setPosition(float x, float z, float y) {
	((QuadTreeEntryImplementation*) impl)->setPosition(x, z, y);
}

void QuadTreeEntryAdapter::initializePosition(float x, float z, float y) {
	((QuadTreeEntryImplementation*) impl)->initializePosition(x, z, y);
}

int QuadTreeEntryAdapter::compareTo(QuadTreeEntry* obj) {
	return ((QuadTreeEntryImplementation*) impl)->compareTo(obj);
}

bool QuadTreeEntryAdapter::isInQuadTree() {
	return ((QuadTreeEntryImplementation*) impl)->isInQuadTree();
}

int QuadTreeEntryAdapter::inRangeObjectCount() {
	return ((QuadTreeEntryImplementation*) impl)->inRangeObjectCount();
}

unsigned long long QuadTreeEntryAdapter::getObjectID() {
	return ((QuadTreeEntryImplementation*) impl)->getObjectID();
}

float QuadTreeEntryAdapter::getRadius() {
	return ((QuadTreeEntryImplementation*) impl)->getRadius();
}

bool QuadTreeEntryAdapter::isBounding() {
	return ((QuadTreeEntryImplementation*) impl)->isBounding();
}

void QuadTreeEntryAdapter::setBounding() {
	((QuadTreeEntryImplementation*) impl)->setBounding();
}

void QuadTreeEntryAdapter::clearBounding() {
	((QuadTreeEntryImplementation*) impl)->clearBounding();
}

/*
 *	QuadTreeEntryHelper
 */

QuadTreeEntryHelper* QuadTreeEntryHelper::staticInitializer = QuadTreeEntryHelper::instance();

QuadTreeEntryHelper::QuadTreeEntryHelper() {
	className = "QuadTreeEntry";

	Core::getObjectBroker()->registerClass(className, this);
}

void QuadTreeEntryHelper::finalizeHelper() {
	QuadTreeEntryHelper::finalize();
}

DistributedObject* QuadTreeEntryHelper::instantiateObject() {
	return new QuadTreeEntry(DummyConstructorParameter::instance());
}

DistributedObjectServant* QuadTreeEntryHelper::instantiateServant() {
	return new QuadTreeEntryImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* QuadTreeEntryHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new QuadTreeEntryAdapter((QuadTreeEntryImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

