target_sources(engine3
	PRIVATE
		AABBTree.cpp
		BasicOcTree.cpp
		BasicQuadTree.cpp
		Funnel.cpp
		Matrix4.cpp
		Segment.cpp
		Sphere.cpp
		Triangle.cpp
		TriangulationAStarAlgorithm.cpp
	PUBLIC
	FILE_SET public_headers
	TYPE HEADERS
	BASE_DIRS ${PROJECT_SOURCE_DIR}/src
	FILES
		AABB.h
		AABBNode.h
		AABBTree.h
		AStarAlgorithm.h
		BasicOcTree.h
		BasicOcTreeNode.h
		BasicQuadTree.h
		BasicQuadTreeNode.h
		Coordinate.h
		Funnel.h
		Matrix3.h
		Matrix4.h
		OcTreeEntryInterface.h
		QuadTreeEntryInterface.h
		Quaternion.h
		Ray.h
		Segment.h
		Sphere.h
		Triangle.h
		TriangleNode.h
		TriangulationAStarAlgorithm.h
		Vector3.h
		Vector4.h
)


