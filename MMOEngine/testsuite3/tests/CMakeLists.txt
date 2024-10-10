generate_idl("TestIDLClass.idl" testsuite3)
generate_idl("TestNoOrbClass.idl" testsuite3)

target_include_directories(testsuite3 
    PRIVATE 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_sources(testsuite3
	PRIVATE
        allocatorhook.h
        convertdatabases.h
        databasetests.h
        hashtableiterator.h
        loggertest.h
        lowerbound.h
        memprottest.h
        orbtest.h
        qtboundingtest.h
        qtstmtest.h
        randomtest.h
        referencetest.h
        regexptest.h
        serializableconvert.h
        sizeoftest.h
        stmmemtest.h
        stmtest.h
        TestClass.h
        ${CMAKE_CURRENT_BINARY_DIR}/TestIDLClass.cpp
		${CMAKE_CURRENT_BINARY_DIR}/TestIDLClass.h
        ${CMAKE_CURRENT_BINARY_DIR}/TestNoOrbClass.cpp
		${CMAKE_CURRENT_BINARY_DIR}/TestNoOrbClass.h
        threadlocal.h
        timeserialize.h
        udptest.h
        weakreftest.h
)