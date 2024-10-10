target_sources(engine3
	PRIVATE
		PriorityQueue.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		ArrayList.h
		ArrayQueue.h
		BinaryHeap.h
		BinarySearchTree.h
		HashSet.h
		HashTable.h
		Iterator.h
		LinkedList.h
		MPSCNode.h
		MPSCQueue.h
		Optional.h
		optional.hpp
		PriorityQueue.h
		SortedVector.h
		StaticMap.h
		SynchronizedHashTable.h
		SynchronizedLinkedList.h
		SynchronizedSortedVector.h
		SynchronizedVector.h
		SynchronizedVectorMap.h
		TickTimer.h
		Timer.h
		Vector.h
		VectorMap.h
		VectorSet.h
)


