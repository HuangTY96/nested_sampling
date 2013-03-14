#include <math.h>

// TODO: make a lennard jones class! for now just do a function for testing

double lj(double *x1, double *x2, double eps, double sig)
{
  double d[3], r2=0;
  double sig2 = sig*sig;
  double ir6 = 0;
  int i;
  
  for(i=0; i<3; ++i) {
    d[i] = x2[i] - x1[i];
    r2 += d[i]*d[i];
  }
  ir6 = pow(sig2/r2, 3);
  
  return 4.*eps*(ir6 * ir6 - ir6);
}

double ljenergy(double * x, int N, double eps, double sig)
{
  double r[3];
  int i, j;
 
  double energy = 0;
  for(i=0; i<N; i+=3) 
    for(j=i+3; j<N; j+=3)
      energy += lj(&x[i], &x[j], eps, sig);
  return energy;
}

//double ljg(double * __restrict__ x1, double * __restrict__ x2, double * __restrict__ g,
//		double eps, double sig)
//{
//  double r2=0;
//  
//  for(int i=0; i<3; ++i) {
//    g[i]=x2[i] - x1[i];
//    r2+=g[i]*g[i];
//  }
//  //r2+=g[0]*g[0] + g[1]*g[1] + g[2]*g[2];
//  
//  double r6 = 1./(r2*r2*r2);
//  double r12 = r6*r6;
//  double sig6 = pow(sig,6);
//  double sig12 = sig6*sig6;
//  
//  for(int i=0; i<3; ++i)
//    g[i]*=4.0*eps*(12. * sig12 * r12 -  6. * sig6 * r6)/r2;
//  
//  return 4. * eps * (sig12 * r12 - sig6 * r6);
//}
//
//double gradient(boost::python::numeric::array& px, boost::python::numeric::array& pgrad,
//		double eps, double sig)
//{
//  int N;
//  double gtmp[3];
//  
//  NPArray<1> x(px);
//  NPArray<1> g(pgrad);
// 
//  N=x.size(0);
//  for(int i=0; i<N; ++i)
//    g[i]=0.0;
//  
//  double energy = 0;
//  for(int i=0; i<N; i+=3)
//    for(int j=i+3; j<N; j+=3) {
//      energy+=ljg(&x[i], &x[j], gtmp, eps, sig);
//      for(int k=0; k<3; ++k) {
//        g[i+k]+=gtmp[k];
//        g[j+k]-=gtmp[k];	
//      }
//    }
//  return energy;
//}
//
//#if 0
////aborted attempt
////need an integer version of NPArray
//double gradient_list(boost::python::numeric::array& px, boost::python::numeric::array& pgrad,
//		double eps, double sig, boost::python::numeric::array& pilist)
//{
//  int N;
//  int Nlist;
//  double gtmp[3];
//  
//  NPArray<1> x(px);
//  NPArray<1> g(pgrad);
//  NPArray<2> ilist(pilist);
// 
//  N=x.size(0);
//  Nlist=ilist.size(0);
//  for(int i=0; i<N; ++i)
//    g[i]=0.0;
//  
//  double energy = 0;
//  for(int k=0; k<Nlist; k+=1)
//      i = (&ilist)[k][0]
//      j = (&ilist)[k][1]
//      energy+=ljg(&x[i], &x[j], gtmp, eps, sig);
//      for(int k=0; k<3; ++k) {
//        g[i+k]+=gtmp[k];
//        g[j+k]-=gtmp[k];	
//      }
//    }
//  return energy;
//}
//#endif
//
//BOOST_PYTHON_MODULE(ljcpp_)
//{
//  using namespace boost::python;
//  import_array();
//  boost::python::numeric::array::set_module_and_type("numpy", "ndarray");
//  def("energy", energy);
//  def("gradient", gradient);
//}
