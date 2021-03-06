#include "FemTech.h"

void StrainDisplacementMatrix(int e, int gp, int nI, double *B) {

	//FT = F.transpose();
	if(ndim == 2) {
		// B in 2D is a 3 x 2 matrix
		double B11,B12,B21,B22,B31,B32;
		double dnIdx = 0.0;
		double dnIdy = 0.0;
		double F11 = 0.0;
		double F21 = 0.0;
		double F12 = 0.0;
		double F22 = 0.0;

		B11 = dnIdx * F11;
		B12 = dnIdx * F21;

		B21 = dnIdy * F12;
		B22 = dnIdy * F22;

		B31 = dnIdx * F12 + dnIdy * F11;
		B32 = dnIdx * F22 + dnIdy * F21;
	}
	if(ndim == 3){
		// B matrix in 3D is a 6 x 3 matrix
    const int indexStart = dsptr[e]+(gp*GaussPoints[e]+nI)*ndim;

		double dnIdx = dshp[indexStart];
		double dnIdy = dshp[indexStart+1];
		double dnIdz = dshp[indexStart+2];

		const int indexStartf = fptr[e] + ndim*ndim*gp;

		double F11 = F[indexStartf];
		double F21 = F[indexStartf+1];
		double F31 = F[indexStartf+2];

		double F12 = F[indexStartf+3];
		double F22 = F[indexStartf+4];
		double F32 = F[indexStartf+5];

		double F13 = F[indexStartf+6];
		double F23 = F[indexStartf+7];
		double F33 = F[indexStartf+8];

		double B11,B12,B13,B21,B22,B23,B31,B32,B33;
		double B41,B42,B43,B51,B52,B53,B61,B62,B63;
		B11 = dnIdx * F11;
		B12 = dnIdx * F21;
		B13 = dnIdx * F31;

		B21 = dnIdy * F12;
		B22 = dnIdy * F22;
		B23 = dnIdy * F32;

		B31 = dnIdz * F13;
		B32 = dnIdz * F23;
		B33 = dnIdz * F33;

		B41 = dnIdy*F13+dnIdz*F12;
    B42 = dnIdy*F23+dnIdz*F22;
    B43 = dnIdy*F33+dnIdz*F32;

		B51 = dnIdx*F13+dnIdz*F11;
    B52 = dnIdx*F23+dnIdz*F21;
    B53 = dnIdx*F33+dnIdz*F31;

		B61 = dnIdx*F12+dnIdy*F11;
    B62 = dnIdx*F22+dnIdy*F21;
    B63 = dnIdx*F32+dnIdy*F31;

    B[0] = B11; B[1] = B21; B[2] = B31; B[3] = B41; B[4] = B51; B[5] = B61;
    B[6] = B12; B[7] = B22; B[8] = B32; B[9] = B42; B[10] = B52; B[11] = B62;
    B[12] = B13; B[13] = B23; B[14] = B33; B[15] = B43; B[16] = B53; B[17] = B63;
	}
	return;
}
