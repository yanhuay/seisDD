!=====================================================================
!
!                   S P E C F E M 2 D  Version 7 . 0
!
!=====================================================================

! setup/constants.h.  Generated from constants.h.in by configure.

!
! solver in single or double precision depending on the machine (4 or 8 bytes)
!
! ALSO CHANGE FILE precision.h ACCORDINGLY
!
  integer, parameter :: SIZE_REAL = 4
  integer, parameter :: SIZE_DOUBLE = 8


! set to SIZE_REAL to run in single precision
! set to SIZE_DOUBLE to run in double precision (increases memory size by 2)
!
! DO CHANGE precision.h accordingly
!
  integer, parameter :: CUSTOM_REAL = SIZE_REAL

!----------- parameters that can be changed by the user -----------

!!-----------------------------------------------------------
!!
!! Gauss-Lobatto-Legendre resolution
!!
!!-----------------------------------------------------------

! number of Gauss-Lobatto-Legendre (GLL) points (i.e., polynomial degree + 1)
  integer, parameter :: NGLLX = 5

! number of Gauss-Lobatto-Jacobi (GLJ) points in the axial elements (i.e., polynomial degree + 1)
! the code does NOT work if NGLJ /= NGLLX so far
  integer, parameter :: NGLJ = NGLLX

! the code does NOT work if NGLLZ /= NGLLX because it then cannot handle a non-structured mesh
! due to non matching polynomial degrees along common edges
  integer, parameter :: NGLLZ = NGLLX

!!-----------------------------------------------------------
!!
!! I/O output
!!
!!-----------------------------------------------------------

! input and output files
  integer, parameter :: ISTANDARD_OUTPUT = 6
  integer, parameter :: IIN  = 40, IOUT = 41

! uncomment this to write to standard output (i.e. to the screen)
  integer, parameter :: IMAIN = ISTANDARD_OUTPUT
! uncomment this to write messages to a text file
! integer, parameter :: IMAIN = 42

  integer, parameter :: IOUT_UNDO_ATT = 45
  integer, parameter :: IIN_UNDO_ATT = IOUT_UNDO_ATT

! output file for energy
  integer, parameter :: IOUT_ENERGY = 77

!!-----------------------------------------------------------
!!
!! source/receiver setup
!!
!!-----------------------------------------------------------

! interpolates position to find the best possible location for the source, between GLL points if needed.
! note: this can be turned off to speedup location search and locate the source at the closest GLL point instead.
  logical, parameter :: USE_BEST_LOCATION_FOR_SOURCE = .true.

! maximum length of station and network name for receivers
  integer, parameter :: MAX_LENGTH_STATION_NAME = 32
  integer, parameter :: MAX_LENGTH_NETWORK_NAME = 8

! we mimic a triangle of half duration equal to half_duration_triangle
! using a Gaussian having a very close shape, as explained in Figure 4.2
! of the manual. This source decay rate to mimic an equivalent triangle
! was found by trial and error
  double precision, parameter :: SOURCE_DECAY_MIMIC_TRIANGLE = 1.628d0

!!-----------------------------------------------------------
!!
!! for attenuation
!!
!!-----------------------------------------------------------

! use SolvOpt nonlinear optimization with constraints or less accurate classical linear least squares
  logical, parameter :: USE_SOLVOPT = .true.

! to compute optimized weights for attenuation (1 means we work in frequency, 2 PI means we work in angular frequency)
  double precision, parameter :: TWO_PI_OR_ONE = 1.d0 ! TWO_PI

! update the memory variables using a convolution or using a differential equation
  logical, parameter :: CONVOLUTION_MEMORY_VARIABLES = .false.


!!-----------------------------------------------------------
!!
!! poroelasticity
!!
!!-----------------------------------------------------------

! viscid flow controlled by fluid viscosity eta_f parameter (eta_f is zero for no viscosity)
! for ideal fluid (neglecting viscosity) and inviscid flow set to .false.
  logical, parameter :: USE_PORO_VISCOUS_DAMPING = .true.


!!-----------------------------------------------------------
!!
!! noise simulations
!!
!!-----------------------------------------------------------

! type of noise source time function:
! 0=external, 1=Ricker(second derivative), 2=Ricker(first derivative), 3=Gaussian, 4=Figure 2a of Tromp et al. 2010
!
! default value 4 is chosen to reproduce the time function from Fig 2a of
! "Tromp et al., 2010, Noise Cross-Correlation Sensitivity Kernels"
  integer, parameter :: noise_source_time_function_type = 4

! For noise tomography only - specify whether to reconstruct ensemble forward
! wavefield by saving everywhere or by saving only at the boundaries (the
! latter usually much faster but prone to artefacts)
  logical, parameter :: NOISE_SAVE_EVERYWHERE = .false.

! this is movie file output only in the case of noise tomography
  logical,parameter :: NOISE_MOVIE_OUTPUT = .false.

!!-----------------------------------------------------------
!!
!! kernels
!!
!!-----------------------------------------------------------

! outputs diagonal Hessian for preconditioning
  logical, parameter :: APPROXIMATE_HESS_KL = .true.


!!-----------------------------------------------------------
!!
!! image plots
!!
!!-----------------------------------------------------------

! maximum size of the X and Z directions of a JPEG image generated by the display routine
  integer, parameter :: NX_NZ_IMAGE_MAX = 10000

! in PostScript files about mesh quality, show all elements above this threshold
  double precision, parameter :: THRESHOLD_POSTSCRIPT = 95.d0 / 100.d0

! option to display only part of the mesh and not the whole mesh,
! for instance to analyze Cuthill-McKee mesh partitioning etc.
! Possible values are:
!  1: display all the elements (i.e., the whole mesh)
!  2: display inner elements only
!  3: display outer elements only
!  4: display a fixed number of elements (in each partition) only
  integer, parameter :: DISPLAY_SUBSET_OPTION = 1
! number of spectral elements to display in each subset when a fixed subset size is used (option 4 above)
  integer, parameter :: NSPEC_DISPLAY_SUBSET = 2300

! X and Z axis origin of PostScript plot in centimeters
  double precision, parameter :: ORIG_X = 2.4d0
  double precision, parameter :: ORIG_Z = 2.9d0

! dot to centimeter conversion for PostScript
  double precision, parameter :: CENTIM = 28.5d0

! parameters for arrows for PostScript snapshot
  double precision, parameter :: ARROW_ANGLE = 20.d0
  double precision, parameter :: ARROW_RATIO = 0.40d0

! size of frame used for Postscript display in percentage of the size of the page
  double precision, parameter :: RPERCENTX = 70.0d0,RPERCENTZ = 77.0d0

! color images (1==colored / 0==black&white) (both postscript and jpeg)
  integer,parameter :: DISPLAY_COLORS = 1

! adds numbers to mesh elements (1==on / 0==off)
  integer,parameter :: DISPLAY_ELEMENT_NUMBERS_POSTSCRIPT = 0

! for PMLs
! remove the PMLs from JPEG images if needed: set the vector field to zero there
  logical, parameter :: REMOVE_PMLS_FROM_JPEG_IMAGES = .true.

! display all the PML layers in a different (constant) color in the PostScript vector plots if needed
  logical, parameter :: DISPLAY_PML_IN_DIFFERENT_COLOR = .true.
  integer, parameter :: ICOLOR_FOR_PML_DISPLAY = 100

!!-----------------------------------------------------------
!!
!! partitioning
!!
!!-----------------------------------------------------------

!--- beginning of Nicolas Le Goff's constants for an unstructured CUBIT/METIS/SCOTCH mesh

! maximum number of neighbors per element
  integer, parameter :: MAX_NEIGHBORS = 40

! maximum number of elements that can contain the same node
  integer, parameter :: MAX_NSIZE_SHARED = 40

!--- end of Nicolas Le Goff's constants for an unstructured CUBIT/METIS/SCOTCH mesh

! select fast (Paul Fischer) or slow (topology only) global numbering algorithm
  logical, parameter :: FAST_NUMBERING = .true.

! mesh tolerance for fast global numbering
  double precision, parameter :: SMALLVALTOL = 1.d-10

!!-----------------------------------------------------------
!!
!! small crack
!!
!!-----------------------------------------------------------

! add a small crack (discontinuity) in the medium manually
  logical, parameter :: ADD_A_SMALL_CRACK_IN_THE_MEDIUM = .false.

! must be set equal to the number of spectral elements on one vertical side of the crack
  integer, parameter :: NB_POINTS_TO_ADD_TO_NPGEO = 3

!!-----------------------------------------------------------
!!
!! CPML perfectly matched absorbing layers
!!
!!-----------------------------------------------------------

! flags for CPML absorbing boundaries
  integer, parameter :: CPML_X_ONLY = 1
  integer, parameter :: CPML_Z_ONLY = 2
  integer, parameter :: CPML_XZ_ONLY = 3

! flags decide that do PML_parameter_adjustment implemented in pml_init.F90 or not
  logical, parameter :: PML_parameter_adjustment = .false.

!!-----------------------------------------------------------
!!
!! mesh coloring for GPUs (not needed any more, obsolete)
!!
!!-----------------------------------------------------------

! for CUDA mode
  logical, parameter :: USE_MESH_COLORING_GPU = .false.


!!-----------------------------------------------------------
!!
!! moving source location
!!
!!-----------------------------------------------------------

! For moving sources
  logical, parameter :: SOURCE_IS_MOVING = .false.

!!-----------------------------------------------------------
!!
!! enforces wavefield
!!
!!-----------------------------------------------------------

! This option is used when we want to enforce fields
  logical, parameter :: USE_ENFORCE_FIELDS = .false.



!------------------------------------------------------
!----------- do not modify anything below -------------
!------------------------------------------------------

! number of spatial dimensions
  integer, parameter :: NDIM = 2

! number of edges and corners of each element
  integer, parameter :: NEDGES = 4
  integer, parameter :: NCORNERS = 4

! number of points per surface element
  integer, parameter :: NGLLSQUARE = NGLLX * NGLLZ

! displacement threshold above which we consider the code became unstable
  double precision, parameter :: STABILITY_THRESHOLD = 1.d+25

! a few useful constants
  double precision, parameter :: ZERO = 0.d0,ONE = 1.d0
  double precision, parameter :: HALF = 0.5d0,TWO = 2.d0,QUARTER = 0.25d0

! pi
  double precision, parameter :: PI = 3.141592653589793d0
  double precision, parameter :: TWO_PI = 2.d0 * PI

! 2/3
  double precision, parameter :: TWO_THIRDS = 2.d0/3.d0

! 4/3
  double precision, parameter :: FOUR_THIRDS = 4.d0/3.d0

! 1/24
  double precision, parameter :: ONE_OVER_24 = 1.d0 / 24.d0

! very large and very small values
  double precision, parameter :: HUGEVAL = 1.d+30,TINYVAL = 1.d-9

! do not use tags for MPI messages, use dummy tag instead
  integer, parameter :: itag = 0

! for the Gauss-Lobatto-Legendre points and weights
  double precision, parameter :: GAUSSALPHA = 0.d0,GAUSSBETA = 0.d0

! number of lines per source in SOURCE file
  integer, parameter :: NLINES_PER_SOURCE = 14

! number of iterations to solve the system for xi and eta
! setting it to 5 instead of 4 ensures that the result obtained is not compiler dependent
! (when using 4 only some small discrepancies were observed)
  integer, parameter :: NUM_ITER = 5

! ignore variable name field (junk) at the beginning of each input line
  logical, parameter :: IGNORE_JUNK = .true., DONT_IGNORE_JUNK = .false.

! maximum length of strings used for paths, reading from files, etc.
  integer, parameter :: MAX_STRING_LEN = 512


!!-----------------------------------------------------------
!!
!! DOMAINS
!!
!!-----------------------------------------------------------

! flag to indicate an isotropic elastic/acoustic material
! flag to indicate an anisotropic material
! flag to indicate a poroelastic material
  integer, parameter :: ISOTROPIC_MATERIAL = 1
  integer, parameter :: ANISOTROPIC_MATERIAL = 2
  integer, parameter :: POROELASTIC_MATERIAL = 3

! file number for interface file
  integer, parameter :: IIN_INTERFACES = 15


! flags for Stacey absorbing boundaries
  integer, parameter :: IBOTTOM = 1
  integer, parameter :: IRIGHT = 2
  integer, parameter :: ITOP = 3
  integer, parameter :: ILEFT = 4

  integer, parameter :: IEDGE1 = 1
  integer, parameter :: IEDGE2 = 2
  integer, parameter :: IEDGE3 = 3
  integer, parameter :: IEDGE4 = 4

! flag to indicate an element type
! material domain ids (acoustic/elastic/poroelastic/gravitoacoustic)
  integer, parameter :: IDOMAIN_ACOUSTIC    = 1
  integer, parameter :: IDOMAIN_ELASTIC     = 2
  integer, parameter :: IDOMAIN_POROELASTIC = 3
  integer, parameter :: IDOMAIN_GRAVITOACOUSTIC = 4


!!-----------------------------------------------------------
!!
!! for LDDRK high-order time scheme
!!
!!-----------------------------------------------------------

! Low-dissipation and low-dispersion fourth-order Runge-Kutta algorithm
!
! reference:
! J. Berland, C. Bogey, and C. Bailly.
! Low-dissipation and low-dispersion fourth-order Runge-Kutta algorithm.
! Computers and Fluids, 35:1459-1463, 2006
!
! see: http://www.sciencedirect.com/science/article/pii/S0045793005000575?np=y

! maximum number of stages for optimized (for reduced storage) LDDRK4-6 Runge-Kutta time scheme
  integer, parameter :: NSTAGE = 6

! coefficients from Table 1, Berland et al. (2006)
! (parameters used in LDDRK scheme, from equation (2) of Berland et al.)
  real(kind=CUSTOM_REAL), dimension(NSTAGE), parameter :: ALPHA_LDDRK = &
    (/0.0_CUSTOM_REAL,-0.737101392796_CUSTOM_REAL, -1.634740794341_CUSTOM_REAL, &
      -0.744739003780_CUSTOM_REAL,-1.469897351522_CUSTOM_REAL,-2.813971388035_CUSTOM_REAL/)

  real(kind=CUSTOM_REAL), dimension(NSTAGE), parameter :: BETA_LDDRK = &
    (/0.032918605146_CUSTOM_REAL,0.823256998200_CUSTOM_REAL,0.381530948900_CUSTOM_REAL, &
      0.200092213184_CUSTOM_REAL,1.718581042715_CUSTOM_REAL,0.27_CUSTOM_REAL/)

  real(kind=CUSTOM_REAL), dimension(NSTAGE), parameter :: C_LDDRK = &
    (/0.0_CUSTOM_REAL,0.032918605146_CUSTOM_REAL,0.249351723343_CUSTOM_REAL, &
      0.466911705055_CUSTOM_REAL,0.582030414044_CUSTOM_REAL,0.847252983783_CUSTOM_REAL/)


