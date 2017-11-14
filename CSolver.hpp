#ifndef _CSOLVERH_
#define _CSOLVERH_

#include "Macros.hpp"
#include "Utils.hpp"
#include "BC.hpp"
#include "TimeStepping.hpp"
#include "IdealGas.hpp"
#include "SpongeBC.hpp"

class CSolver{

    public:

	Domain *dom;
	BC *bc;
	TimeStepping *ts;
	IdealGas *ig;
	double alphaF;
	double mu_ref;

	//Make local copies for macros...
	int Nx, Ny, Nz, N;

	//initial conditions
	double *rho0, 
	         *U0,
	         *V0,
		 *W0,
		 *p0;
	
	//non-conserved data
	double  *U, 
		*V,
		*W,
	        *T,
		*p,
	       *mu,
		*k, 
	      *sos;

	//derivatives of data
	double *Ux, *Uy, *Uz;
	double *Vx, *Vy, *Vz;
	double *Wx, *Wy, *Wz;

	double *Uxx, *Uyy, *Uzz;
	double *Vxx, *Vyy, *Vzz;
	double *Wxx, *Wyy, *Wzz;

	double *Uxy, *Uxz, *Uyz;
	double *Vxy, *Vxz, *Vyz;
	double *Wxy, *Wxz, *Wyz;

	double *Tx,  *Ty,  *Tz;
	double *Txx, *Tyy, *Tzz;

	double *contEulerX, *contEulerY, *contEulerZ;
	double *momXEulerX, *momXEulerY, *momXEulerZ;
	double *momYEulerX, *momYEulerY, *momYEulerZ;
	double *momZEulerX, *momZEulerY, *momZEulerZ;
	double *engyEulerX, *engyEulerY, *engyEulerZ;

	double *rho1,  *rhok,  *rhok2,  *rho2; 
	double *rhoU1, *rhoUk, *rhoUk2, *rhoU2; 
	double *rhoV1, *rhoVk, *rhoVk2, *rhoV2; 
	double *rhoW1, *rhoWk, *rhoWk2, *rhoW2; 
	double *rhoE1, *rhoEk, *rhoEk2, *rhoE2;

	bool spongeFlag;
	SpongeBC *spg; 



	CSolver(Domain *dom, BC *bc, TimeStepping *ts, double alphaF, double mu_ref){

	    //Take in input information and initialize data structures...
	    this->dom = dom;
	    this->bc = bc;
	    this->ts = ts;
	    this->alphaF = alphaF;
	    this->mu_ref = mu_ref;

	    ig = new IdealGas(dom);

	    Nx = dom->Nx;
	    Ny = dom->Ny;
	    Nz = dom->Nz;
	    N  = dom->N;

	    initializeSolverData();		    	    


	}


	void initializeSolverData();

};

/*
void CSolver::initializeSolverData(){

    cout << " > Allocating Solver Arrays..." << endl;
    long unsigned int workSize = 0;
    workSize = 68 * N * 8;
    cout << " > Need " << workSize/1024.0/1024.0/1024.0 << " Gb of memory to allocated solver arrays " << endl;

    //3
    Ux = new double[N];
    Uy = new double[N];
    Uz = new double[N];

    //6
    Vx = new double[N];
    Vy = new double[N];
    Vz = new double[N];

    //9
    Wx = new double[N];
    Wy = new double[N];
    Wz = new double[N];

    //12
    Uxx = new double[N];
    Uyy = new double[N];
    Uzz = new double[N];

    //15
    Vxx = new double[N];
    Vyy = new double[N];
    Vzz = new double[N];

    //18
    Wxx = new double[N];
    Wyy = new double[N];
    Wzz = new double[N];

    //21
    Uxy = new double[N];
    Uxz = new double[N];
    Uyz = new double[N];

    //24
    Vxy = new double[N];
    Vxz = new double[N];
    Vyz = new double[N];

    //27
    Wxy = new double[N];
    Wxz = new double[N];
    Wyz = new double[N];

    //30
    Tx = new double[N];
    Ty = new double[N];
    Tz = new double[N];

    //33
    Txx = new double[N];
    Tyy = new double[N];
    Tzz = new double[N];

    //36
    contEulerX = new double[N];
    contEulerY = new double[N];
    contEulerZ = new double[N];

    //39
    momXEulerX = new double[N];
    momXEulerY = new double[N];
    momXEulerZ = new double[N];

    //42
    momYEulerX = new double[N];
    momYEulerY = new double[N];
    momYEulerZ = new double[N];

    //45
    momZEulerX = new double[N];
    momZEulerY = new double[N];
    momZEulerZ = new double[N];

    //48
    engyEulerX = new double[N];
    engyEulerY = new double[N];
    engyEulerZ = new double[N];

    //52
    rho1  = new double[N];
    rhok  = new double[N];
    rhok2 = new double[N];
    rho2  = new double[N];

    //56
    rhoU1  = new double[N];
    rhoUk  = new double[N];
    rhoUk2 = new double[N];
    rhoU2  = new double[N];

    //60
    rhoV1  = new double[N];
    rhoVk  = new double[N];
    rhoVk2 = new double[N];
    rhoV2  = new double[N];

    //64
    rhoW1  = new double[N];
    rhoWk  = new double[N];
    rhoWk2 = new double[N];
    rhoW2  = new double[N];

    //68
    rhoE1  = new double[N];
    rhoEk  = new double[N];
    rhoEk2 = new double[N];
    rhoE2  = new double[N];

}
*/
#endif
