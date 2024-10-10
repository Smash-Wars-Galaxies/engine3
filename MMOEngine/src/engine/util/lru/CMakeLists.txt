target_sources(engine3
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		lru_cache.h
		lru_cache_using_engine3.h
		lru_cache_using_std.h
		lru_cache_using_std_c98.h
		LRUCache.h
		SynchronizedLRUCache.h
)


