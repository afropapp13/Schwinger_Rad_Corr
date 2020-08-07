//____________________________________________________________________________
/*!

\class    genie::QELKinematicsGenerator

\brief    Generates values for the kinematic variables describing QEL neutrino
          interaction events.
          Is a concrete implementation of the EventRecordVisitorI interface.

\author   Costas Andreopoulos <constantinos.andreopoulos \at cern.ch>
          University of Liverpool & STFC Rutherford Appleton Laboratory

\created  October 03, 2004

\cpright  Copyright (c) 2003-2020, The GENIE Collaboration
          For the full text of the license visit http://copyright.genie-mc.org          
*/
//____________________________________________________________________________

#ifndef _QEL_KINEMATICS_GENERATOR_H_
#define _QEL_KINEMATICS_GENERATOR_H_

#include "Physics/Common/KineGeneratorWithCache.h"
#include "Framework/Utils/Range1.h"

namespace genie {

class QELKinematicsGenerator : public KineGeneratorWithCache {

public :
  QELKinematicsGenerator();
  QELKinematicsGenerator(string config);
 ~QELKinematicsGenerator();

  // implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  // overload the Algorithm::Configure() methods to load private data
  // members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void SpectralFuncExperimentalCode(GHepRecord * event_rec) const;
  TLorentzVector GetFinalStateLeptonKinematic(GHepRecord * evrec, double E, double gy, double gQ2) const; 
  virtual void AddToEventRecord(GHepRecord * evrec, int pdgc, TLorentzVector & p4) const;
  virtual void SetPolarization(GHepRecord * evrec) const;
  void   LoadConfig     (void);
  double ComputeMaxXSec (const Interaction * in) const;

  bool fDoRadiativeCorrection;
  std::string fModel;               ///< to distinguish between differnt models, right now simc / vanderhagen
  double      fCutoff;
  double      fThickness;           ///< thicnknesses of targets in CLAS in radiation length 
  bool        fdoInternal;
  bool fApplyCoulombCorrection;
};

}      // genie namespace
#endif // _QEL_KINEMATICS_GENERATOR_H_
