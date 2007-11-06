// -*- c++ -*-
//*****************************************************************************
/** @file cuddinterface.cc
 *
 * @author Alexander Dreyer
 * @date 2006-03-06
 *
 * This file contains tests for the Boolean Variables.
 *
 * @par Copyright:
 *   (c) 2006 by The PolyBoRi Team
 *
 * @internal 
 * @version \$Id$
 *
 * @par History:
 * @verbatim
 * $Log$
 * Revision 1.9  2007/11/06 15:15:27  dreyer
 * Fix: typo
 *
 * Revision 1.8  2007/11/06 15:03:42  dreyer
 * CHANGE: More generic copyright
 *
 * Revision 1.7  2007/07/06 18:46:31  dreyer
 * ADD: rewritten C++-Interface for Cudd
 *
 * Revision 1.6  2006/04/21 16:17:12  dreyer
 * ADD template class CTermIter<>
 *
 * Revision 1.5  2006/04/20 08:31:22  dreyer
 * ADD BooleMonomial::mulples(...)
 *
 * Revision 1.4  2006/03/29 16:20:12  dreyer
 * CHANGE: revised testsuite
 *
 * Revision 1.3  2006/03/27 13:47:58  dreyer
 * ADD operator + and *, CHANGE BoolePolyRing::variable(i) generation
 *
 * Revision 1.2  2006/03/22 16:39:54  dreyer
 * ADD Switch for using valgrind
 *
 * Revision 1.1  2006/03/22 08:06:59  dreyer
 * ADD: Template specializations CDDInterface<ZDD>, CDDManager<Cudd>; 
 * ring uses shared_ptr now
 *
 * @endverbatim
**/
//*****************************************************************************


// load standard iostream capapilities
#include <iostream>

// load polybori header file
#include "polybori.h"

// cudd interface
#include "CDDManager.h"

USING_NAMESPACE_PBORI

int
main(){

  std::cout << "Testing cudd interface" <<std::endl;   

  try {
    CDDManager<CTypes::manager_base> man(3);

    CTypes::dd_type dd0 (man.ddVariable(0));
    std::cout << dd0;

    CTypes::dd_type dd1 ( man.ddVariable(1));
    std::cout << dd1;

    dd0.unateProductAssign(dd1);
    std::cout << dd0;

    dd0 = man.ddVariable(0);
    dd0.subset0Assign(1);
    dd0.subset0Assign(2);

    std::cout << dd0;
    dd1.subset0Assign(0);
    dd1.subset0Assign(2);

     std::cout << dd1;

    dd0.unateProductAssign(dd1);
    std::cout << dd0;

    dd0.uniteAssign( man.ddVariable(2) );
    std::cout << dd0;

  }
  catch (PBoRiError& err) {
    std::cout << "  Caught error # "<< err.code() <<std::endl;   
    std::cout << "    which says: "<< err.text() <<std::endl;  
 }

  return 0;
}
