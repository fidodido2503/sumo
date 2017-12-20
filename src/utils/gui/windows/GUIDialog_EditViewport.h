/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2017 German Aerospace Center (DLR) and others.
/****************************************************************************/
//
//   This program and the accompanying materials
//   are made available under the terms of the Eclipse Public License v2.0
//   which accompanies this distribution, and is available at
//   http://www.eclipse.org/legal/epl-v20.html
//
/****************************************************************************/
/// @file    GUIDialog_EditViewport.h
/// @author  Daniel Krajzewicz
/// @author  Michael Behrisch
/// @date    2005-05-04
/// @version $Id$
///
// A dialog to change the viewport
/****************************************************************************/
#ifndef GUIDialog_EditViewport_h
#define GUIDialog_EditViewport_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <fx.h>

// ===========================================================================
// class declarations
// ===========================================================================
class GUISUMOAbstractView;
class Position;


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class GUIDialog_EditViewport
 * @brief A dialog to change the viewport
 */
class GUIDialog_EditViewport : public FXDialogBox {
    // FOX-declarations
    FXDECLARE(GUIDialog_EditViewport)
public:
    /// @brief FOX-callback enumerations
    enum {
        MID_CHANGED = FXDialogBox::ID_LAST,
        MID_OK,
        MID_CANCEL,
        MID_LOAD,
        MID_SAVE
    };


    /** @brief Constructor
     * @param[in] parent The view to change
     * @param[in] name This dialog's caption
     * @param[in] x x-position to show the dialog at
     * @param[in] y y-position to show the dialog at
     */
    GUIDialog_EditViewport(GUISUMOAbstractView* parent,  const char* name, int x, int y);

    /// @brief Destructor
    ~GUIDialog_EditViewport();

    /// @brief overload show function to focus always in OK Button
    void show();

    /// @name FOX-callbacks
    /// @{

    /// Called when the user changes the viewport
    long onCmdChanged(FXObject*, FXSelector, void*);

    /// Called when the user wants to keep the viewport
    long onCmdOk(FXObject*, FXSelector, void*);

    /// Called when the user wants to restore the viewport
    long onCmdCancel(FXObject*, FXSelector, void*);

    /// Called when the user wants to load a viewport
    long onCmdLoad(FXObject*, FXSelector, void*);

    /// Called when the user wants to save a viewport
    long onCmdSave(FXObject*, FXSelector, void*);
    /// @}

    /// write the settings to the given device
    void writeXML(OutputDevice& dev);

    /** @brief Sets the given values into the dialog
     * @param[in] zoom Current view's zoom
     * @param[in] xoff Current view's x-offset
     * @param[in] yoff Current view's y-offset
     */
    void setValues(double zoom, double xoff, double yoff);

    /** @brief Sets the given values into the dialog
     * @param[in] lookFrom Current viewport's from
     * @param[in] lookAt Current viewport's at
     */
    void setValues(const Position& lookFrom, const Position& lookAt);

    /** @brief Resets old values
     * @param[in] lookFrom Current viewport's from
     * @param[in] lookAt Current viewport's at
     */
    void setOldValues(const Position& lookFrom, const Position& lookAt);

    /** @brief Returns the information whether one of the spin dialers is grabbed
     * @return Whether the spin dialers are currently used
     */
    bool haveGrabbed() const;


protected:
    /// @brief The calling view
    GUISUMOAbstractView* myParent;

    /// @brief The old viewport
    Position myOldLookFrom, myOldLookAt;

    /// @brief The spin dialers used to change the view
    FXRealSpinner* myZoom, *myXOff, *myYOff, *myZOff;

    /// @brief OK button
    FXButton* buttonOk;

#ifdef HAVE_OSG
    /// @brief The spin dialers used to change the view at (osg only)
    FXRealSpinner* myLookAtX, *myLookAtY, *myLookAtZ;
#endif


protected:
    /// @brief FOX needs this
    GUIDialog_EditViewport() { }

};


#endif

/****************************************************************************/

