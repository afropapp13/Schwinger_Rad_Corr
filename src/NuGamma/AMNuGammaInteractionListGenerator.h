//____________________________________________________________________________
/*!

\class    genie::AMNuGammaInteractionListGenerator

\brief    Concrete implementations of the InteractionListGeneratorI interface.
          Generates a list of all the interactions that can be generated by the 
          AM-NUGAMMA EventGenerator.

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          University of Liverpool & STFC Rutherford Appleton Lab

\created  Feb 15, 2008

\cpright  Copyright (c) 2003-2016, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _AMNUGAMMA_INTERACTION_GENERATOR_H_
#define _AMNUGAMMA_INTERACTION_GENERATOR_H_

#include "EVGCore/InteractionListGeneratorI.h"

namespace genie {

class AMNuGammaInteractionListGenerator : public InteractionListGeneratorI {

public :
  AMNuGammaInteractionListGenerator();
  AMNuGammaInteractionListGenerator(string config);
 ~AMNuGammaInteractionListGenerator();

  //-- implement the InteractionListGeneratorI interface
  InteractionList * CreateInteractionList(const InitialState & init) const;
};

}      // genie namespace
#endif // _AMNUGAMMA_INTERACTION_GENERATOR_H_
