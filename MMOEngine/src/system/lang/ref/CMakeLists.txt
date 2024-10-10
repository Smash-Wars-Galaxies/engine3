target_sources(engine3
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		Reference.h
		ReferenceCounter.h
		StrongAndWeakReferenceCount.h
		UniqueReference.h
		WeakReference.h
)


