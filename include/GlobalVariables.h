extern int nparts;
extern int nelements;
extern int nallelements;
extern int nnodes;
extern int ndim;
extern int world_rank;
extern int world_size;


extern double *coordinates;
extern int *connectivity;
extern int *GaussPoints;	/*holds how many guass points per element*/
extern int *gptr;			/*gauss point pointer - helps step through shp array*/
extern int *dsptr;			/*deriviative of shp functions pointer array - helps step through dshp array*/
extern int *gpPtr;			/*gauss point pointer - helps step through detJ and gaussWeights*/
extern int *nShapeFunctions;/*number of shp functions per element */
extern double *shp;			/*shape functions*/
extern double *dshp;		/*derivatives of shape functions*/
extern int *eptr;			/*number of nodes per element pointer*/
extern int *pid;			/* part ID */
extern int *mid;			/*material ID */
extern double *mass;        /*mass matrix*/
extern double *stiffness;        /*stiffness matrix*/
extern double *rhs;              /*to store rhs matrix equation (implicit) */
extern char **ElementType;	/* element type, e.g. C3D8 */

extern double *C; /*Stores C matrix for isotropic elastic material */
extern double rho; /*Stores material density for isotropic material */
extern double *gaussWeights;
extern double *detJacobian;

/* For BC */
extern int nSpecifiedDispBC;

extern double *displacements;
extern int *boundary;
/* Variables required for unsteady problem */
extern double *velocities;
extern double *accelerations;
extern bool unsteadyFlag;

static int debug = 1;

// Variables to keep track of time ans step count
// Initial configuration nStep = 0 and time = 0
// For steady, solution is stored at nStep = 1 and time = 1
// For unsteady nStep and time are set by solver
extern int nStep;
extern double Time;
