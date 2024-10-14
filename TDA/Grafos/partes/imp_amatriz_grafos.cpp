#include "./Assert.cpp"
#include "./tda_grafos.cpp"

// Implementation for the adjacency matrix representation
class Graphm : public Graph {
	private:
		int numVertex, numEdge; // Store number of vertices, edges
		int **matrix;           // Pointer to adjacency matrix
		int *mark;              // Pointer to mark array
	public:
		// Constructor
		Graphm(int numVert)	{ Init(numVert); }
		// Destructor
		~Graphm() { 
			delete [] mark; // Return dynamically allocated memory
			for (int i=0; i<numVertex; i++)
				delete [] matrix[i];
			delete [] matrix;
		}
		// Initialize the graph
		void Init(int n) { 
			int i;
			numVertex = n;
			numEdge = 0;
			mark = new int[n]; // Initialize mark array
			for (i=0; i<numVertex; i++)
				mark[i] = UNVISITED;
			matrix = (int**) new int*[numVertex]; // Make matrix
			for (i=0; i<numVertex; i++)
				matrix[i] = new int[numVertex];
			for (i=0; i< numVertex; i++) // Initialize to 0 weights
				for (int j=0; j<numVertex; j++)
					matrix[i][j] = 0;
		}
		int n() { return numVertex; } // Number of vertices
		int e() { return numEdge; }   // Number of edges
		
		// Return first neighbor of "v"
		int first(int v) {
			for (int i=0; i<numVertex; i++)
				if (matrix[v][i] != 0) 
					return i;
			return numVertex; // Return n if none
		}
		// Return v’s next neighbor after w
		int next(int v, int w) {
			for(int i=w+1; i<numVertex; i++)
				if (matrix[v][i] != 0)
					return i;
			return numVertex; // Return n if none
		}
		// Set edge (v1, v2) to "wt"
		void setEdge(int v1, int v2, int wt) {
			Assert(wt > 0, "Illegal weight value");
			if (matrix[v1][v2] == 0) 
				numEdge++;
			matrix[v1][v2] = wt;
		}
		// Delete edge (v1, v2)
		void delEdge(int v1, int v2) { 
			if (matrix[v1][v2] != 0) 
				numEdge--;
			matrix[v1][v2] = 0;
		}
		// Is (i, j) an edge?
		bool isEdge(int i, int j) { 
			return matrix[i][j] != 0; 
		}
		int weight(int v1, int v2) { return matrix[v1][v2]; }
		int getMark(int v) { return mark[v]; }
		void setMark(int v, int val) { mark[v] = val; }
};