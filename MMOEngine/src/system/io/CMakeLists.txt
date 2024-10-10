target_sources(engine3
	PRIVATE
		BufferedReader.cpp
		File.cpp
		FileDescriptor.cpp
		FileLogWriter.cpp
		IOProcessor.cpp
		Pipe.cpp
		Serializable.cpp
		Stream.cpp
		StringTokenizer.cpp
		TextStream.cpp
		UnicodeTokenizer.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		BufferedReader.h
		File.h
		FileDescriptor.h
		FileInputStream.h
		FileLogWriter.h
		FileNotFoundException.h
		FileOutputStream.h
		FileReader.h
		FileWriter.h
		InputStream.h
		IOException.h
		IOHandler.h
		IOProcessor.h
		ObjectInputStream.h
		ObjectOutputStream.h
		OutputStream.h
		Pipe.h
		Reader.h
		Serializable.h
		Stream.h
		StreamIndexOutOfBoundsException.h
		StringTokenizer.h
		TextStream.h
		UnicodeTokenizer.h
		Writer.h
)


