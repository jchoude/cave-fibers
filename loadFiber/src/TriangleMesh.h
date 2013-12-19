#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H


#include <vector>
#include "DataSetInfo.h"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

struct Triangle 
{
    unsigned int pointID[3];
};

class TriangleMesh 
{
public:
    typedef DataSetInfo::Point Point;
    typedef DataSetInfo::Color Color; // Data type for colors
    typedef DataSetInfo::Vector Vector; // Compatible vector type
    // Constructor / Destructor
    TriangleMesh();
    ~TriangleMesh();

    // Functions
    /*void addVert( const Vector newVert );
    void addVert( const float x, const float y, const float z );*/
    void fastAddVert( const Point newVert );

    /*void addTriangle( const int vertA, const int vertB, const int vertC );
    void addTriangle( const int vertA, const int vertB, const int vertC, const int tensorIndex );*/
    void fastAddTriangle( const int vertA, const int vertB, const int vertC );

    void clearMesh();

    void reserveVerts    ( const int size );
    void reserveTriangles( const int size );
    void resizeVerts     ( const int size );
    void resizeTriangles ( const int size );
    int  getNumVertices();
    int  getNumTriangles();

    Point       getVertex       ( const int vertNum );
    Point       getVertex       ( const int triNum, int pos );
    Vector      getNormal       ( const int triNum  );
    Vector      getVertNormal   ( const int vertNum );
    Color       getVertColor    ( const int vertNum );
    Triangle    getTriangle     ( const int triNum  );
    Color       getTriangleColor( const int triNum  );

    std::vector< unsigned int > getStar( const int vertNum );
    std::vector< Point >       getVerts();

    //int    getTriangleTensor( const int triNum );
    //Vector getTriangleCenter( int triNum ) ;

    void setVertex( const unsigned int vertNum, const Point nPos );
    void setVertColor( const int vertNum, const Color color );

    /*void eraseTriFromVert( const unsigned int triNum, const unsigned int vertNum );
    void setTriangle     ( const unsigned int triNum, const unsigned int vertA, const unsigned int vertB, const unsigned int vertC );
    void setTriangleColor( const unsigned int triNum, const float r, const float g, const float b, const float a );
    void setTriangleColor( const unsigned int triNum, const float r, const float g, const float b );
    void setTriangleAlpha( const unsigned int triNum, const float a );
    void setTriangleRed  ( const unsigned int triNum, const float r );
    void setTriangleGreen( const unsigned int triNum, const float g );
    void setTriangleBlue ( const unsigned int triNum, const float b );

    bool isInTriangle( const unsigned int vertNum, const unsigned int triangleNum );

    bool hasEdge     ( const unsigned int coVert1, const unsigned int coVert2, const unsigned int triangleNum );
    int  getThirdVert( const unsigned int coVert1, const unsigned int coVert2, const unsigned int triangleNum );

    int  getNextVertex( const unsigned int triNum, const unsigned int vertNum );

    void cleanUp();
    void doLoopSubD();

    //void getCellVerticesIndices( const FIndex& cellId, std::vector< FIndex >& vertices );
    //void getPosition( FPosition& resultPos, const FIndex& pIndex );
    //void getEdgeNeighbor( const FIndex& cellId, int pos, std::vector< FIndex >& neigh );
    //void getNeighbors( const FIndex& vertId, std::vector< FIndex >& neighs );
    int  getNeighbor( const unsigned int coVert1, const unsigned int coVert2, const unsigned int triangleNum );
*/
    void   flipNormals();
        

private:
    // Functions
    Vector calcTriangleNormal( const Triangle );
    Vector calcTriangleNormal( const int triNum );
    Vector calcVertNormal( const int vertNum );
    //void   calcTriangleTensors();
    //void   calcNeighbors();
    void   calcVertNormals();

    //void  calcNeighbor( const int triangleNum );

private:
    // Variables
    std::vector< Point >                        m_vertices;
    std::vector< Vector >                       m_vertNormals;
    std::vector< Color >                        m_vertColors;
    std::vector< std::vector< unsigned int > >  m_vIsInTriangle;

    std::vector< Triangle >                     m_triangles;
    std::vector< Vector >                       m_triNormals;
    std::vector< int >                          m_triangleTensor;
    std::vector< Color >                        m_triangleColor;
    std::vector< std::vector< int > >           m_neighbors;

    int    m_numVerts;
    int    m_numTris;

    // We don't delete m_vertices yet, so can do a cleanup only once.
    //bool m_isCleaned;

    bool m_vertNormalsCalculated;
    //bool m_neighborsCalculated;
    //bool m_triangleTensorsCalculated;

    Color m_defaultColor;
};

#endif /* TRIANGLEMESH_H */
