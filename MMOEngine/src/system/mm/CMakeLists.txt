target_sources(engine3
	PRIVATE
		AllocationHook.cpp
		AllocationReplacement.cpp
		AllocationTracker.cpp
		DLAllocator.cpp
		Heap.cpp
		MemoryManager.cpp
		MemoryMappedFile.cpp
		MultimapMemoryManager.cpp
		ProcessHeap.cpp
		ProtectedHeap.cpp
		PTAllocator.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		AllocationHook.h
		AllocationReplacement.h
		AllocationTracker.h
		Allocator.h
		DLAllocator.h
		Heap.h
		MemoryManager.h
		MemoryMappedFile.h
		MultimapMemoryManager.h
		ObjectCloner.h
		ProcessHeap.h
		ProtectedHeap.h
		PTAllocator.h
)

# Add required external dependency
set_source_files_properties(DLAllocator.cpp TARGET_DIRECTORY engine3 PROPERTIES INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/external/dlmalloc")
set_source_files_properties(MultimapMemoryManager.cpp TARGET_DIRECTORY engine3 PROPERTIES INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/external/multimmap")