/* ------------------------------------------------------------------   */
/*      item            : F16HUDOverlay.hxx
        made by         : rvanpaassen
	from template   : DuecaHelperTemplate.hxx
        template made by: Rene van Paassen
        date            : Fri Mar 19 17:06:10 2010
	category        : header file 
        description     : 
	changes         : Fri Mar 19 17:06:10 2010 first version
	template changes: 050825 RvP Added template creation comment
        language        : C++
*/

#ifdef HAVE_WORLDVIEW

#ifndef F16HUDOverlay_hxx
#define F16HUDOverlay_hxx

// include the dueca header
#include <ScriptCreatable.hxx>
#include <stringoptions.h>
#include <ParameterTable.hxx>
#include <dueca_ns.h>
#include <PlibObject.hxx>
#include <string>
#include <vector>

// This includes headers for the objects that are sent over the channels
#include "comm-objects.h"

// my own classes
#include "HUD.hxx"

USING_DUECA_NS;

/** This class is creatable in a dueca.mod script, and can draw a
    simple OpenGL message in a window of the PlibViewer. 

    This has been written as an example and proof-of-concept.

    The WorldView module and its implementation helpers, of which
    PlibViewer is one, are intended as generic 3D visualisation
    implementation for DUECA projects. Since it uses only a simple
    library, easily installable on most Linux distribution, the
    PlibViewer is targeted as the entry-level 3D visualisation for
    DUECA projects. 

    This class is a proof-of-concept for communication between an
    object rendered by the generic WorldView/PlibViewer combination
    and another module, in this case the PlibOverlayTester module. The
    F16HUDOverlay is a class that can be created in a DUECA script,
    and then passed on to a module -- in this case the
    PlibOverlayTester module -- and the PlibViewer. 

    The module can change the data in this object, and the PlibViewer
    renders this object as an OpenGL overlay. The current
    implementation produces nonsense, but serves as an example for
    more useful applications, e.g. instrument overlays or HUD
    overlays. 
   
    This class has been derived from the ScriptCreatable base class,
    and has a (scheme) script command to create it and optionally add
    parameters.

    The instructions to create an object of this class from the Scheme
    script are:

    \verbinclude plib-test-overlay.scm
 */
class F16HUDOverlay: public ScriptCreatable, public PlibObject
{
private: // simulation data
   /** Drawing class. */
  HUD hud;

public:
  inline HUD& getHUD(){return hud;}
 
public: // construction and further specification
  /** Constructor. Is normally called from scheme/the creation script. */
  F16HUDOverlay();

  /** Continued construction. This is called after all script
      parameters have been read and filled in, according to the
      parameter table. */
  bool complete();

  /** Destructor. */
  ~F16HUDOverlay();

  /** Obtain a pointer to the parameter table. */
  static const ParameterTable* getParameterTable();

public:
  /** Draw the overlay */
  void draw(int viewno);

  /** Init with plib root */
  void init(ssgRoot* scene) { hud.InitGL(); }

  /** Returns true to indicate that this object needs drawing post-access */
  bool requirePostDrawAccess() { return true; }

public:
  /** Default script linkage. */
  SCM_FEATURES_DEF;
 
};

#endif

#endif
