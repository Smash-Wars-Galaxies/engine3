target_sources(engine3
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		AtomicBoolean.h
		AtomicInteger.h
		AtomicLong.h
		AtomicReference.h
		AtomicTime.h
)


