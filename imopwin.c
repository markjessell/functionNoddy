/*
	This file was generated by XVT-Design 4.5, a product of:

		XVT Software Inc.
		4900 Pearl East Circle
		Boulder, CO USA 80301
		303-443-4223, fax 303-443-0969

	Generated on Tue Sep 02 10:35:00 1997
*/
/* TAG BEGIN SPCL:Pre_Header */
/* TAG END SPCL:Pre_Header */

#include "xvt.h"
#include "xvtcm.h"
#include "nodInc.h"

/* 
	Information about the window
*/
#define WIN_RES_ID IMAGE_OPTION_WINDOW
#define WIN_FLAGS 0x810L
#define WIN_CLASS ""
#define WIN_BORDER W_DOC
/* TAG BEGIN SPCL:Obj_Decl */
/* TAG END SPCL:Obj_Decl */

/*
	Handler for window IMAGE_OPTION_WINDOW ("Geophysics Plot Options")
*/
long XVT_CALLCONV1
#if XVT_CC_PROTO
IMAGE_OPTION_WINDOW_eh XVT_CALLCONV2 (WINDOW xdWindow, EVENT *xdEvent)
#else
IMAGE_OPTION_WINDOW_eh XVT_CALLCONV2 (xdWindow, xdEvent)
WINDOW xdWindow;
EVENT *xdEvent;
#endif
{
	short xdControlId = xdEvent->v.ctl.id;
	/* TAG BEGIN SPCL:Var_Decl */
	/* TAG END SPCL:Var_Decl */

	switch (xdEvent->type) {
	case E_CREATE:
		/*
			Window has been created; first event sent to newly-created
			window.
		*/
		{
		/* TAG BEGIN EVNT:Create */
		setScrollRange (xdWindow, IMAGE_RANGE_MAX_BAR, 0, 100);
		setScrollRange (xdWindow, IMAGE_RANGE_MIN_BAR, 0, 100);
					/* *********************************** */
					/* setup all the options in the window */
		loadGeophysicsImageOptions (xdWindow);
		
#if (XVTWS != MACWS)
		{
		   SLIST winList;
		   SLIST_ELT element;
		   WINDOW win;
		   WIN_TYPE winType;
		                           /* disable all other windows */
		   winType = xvt_vobj_get_type(xdWindow);
		   if (winType == W_DBL)
		   {
		      if (winList = xvt_scr_list_wins ())
		      {
		         for (element = xvt_slist_get_first(winList); element != NULL;
		                                    element = xvt_slist_get_next (winList, element))
		         {
		            xvt_slist_get (winList, element, (long *) &win);
		            if (win != xdWindow)      /* disable all windows but this one */
		               xvt_vobj_set_enabled (win, FALSE);
		         }
		         xvt_slist_destroy (winList);
		      }
		   }
		}
#endif
		/* TAG END EVNT:Create */
		}
		break;
	case E_DESTROY:
		/*
			Window has been closed; last event sent to window.
		*/
		xdRemoveHelpAssoc( xdWindow );
		{
		/* TAG BEGIN EVNT:Destroy */
#if (XVTWS != MACWS)
		{
		   SLIST winList;
		   SLIST_ELT element;
		   WINDOW win;
		   WIN_TYPE winType;
		                           /* disable all other windows */
		   winType = xvt_vobj_get_type(xdWindow);
		   if (winType == W_DBL)
		   {
		      if (winList = xvt_scr_list_wins ())
		      {
		         for (element = xvt_slist_get_first(winList); element != NULL;
		                                    element = xvt_slist_get_next (winList, element))
		         {
		            xvt_slist_get (winList, element, (long *) &win);
		            if (win != xdWindow)      /* disable all windows but this one */
		               xvt_vobj_set_enabled (win, TRUE);
		         }
		         xvt_slist_destroy (winList);
		      }
		   }
		}
#endif
		/* TAG END EVNT:Destroy */
		}
		break;
	case E_FOCUS:
		{
		/* TAG BEGIN EVNT:Focus */
		/*
			Window has lost or gained focus.
		*/
		if (xdEvent->v.active)  {
			/*
				Window has gained focus
			*/
		} else {
			/*
				Window has lost focus
			*/
#if (XVTWS == MACWS)
#else
		/*
			if (xvt_vobj_get_type (xdWindow) ==  W_DBL)  .* popup Window *.
				xvt_vobj_destroy (xdWindow);
		*/
#endif
		}
		/* TAG END EVNT:Focus */
		}
		break;
	case E_SIZE:
		/*
			Size of window has been set or changed; sent when window is
			created or subsequently resized by user or via xvt_vobj_move.
		*/
		{
		/* TAG BEGIN EVNT:Size */
		/* TAG END EVNT:Size */
		}
		break;
	case E_UPDATE:
		/*
			Window requires updating.
		*/
		{
		/* TAG BEGIN EVNT:Update */
		xvt_dwin_clear(xdWindow, (COLOR)xvt_vobj_get_attr(xdWindow, ATTR_BACK_COLOR));
		/* TAG END EVNT:Update */
		}
		break;
	case E_CLOSE:
		/*
			Request to close window; user operated "close" menu item on
			window system menu, or operated "close" control on window
			frame. Not sent if Close on File menu is issued. Window not
			closed unless xvt_vobj_destroy is called.
		*/
		{
		/* TAG BEGIN EVNT:Close */
		xvt_vobj_destroy(xdWindow);
		/* TAG END EVNT:Close */
		}
		break;
	case E_CHAR:
		/*
			Character typed.
		*/
		{
		/* TAG BEGIN EVNT:Char */
			/* *********************************************** */
			/* make a RETURN key activate the window OK Button */
		if (xdEvent->v.chr.ch == '\r')
		{
		   xdEvent->type = E_CONTROL;
		   xdEvent->v.ctl.id = IMAGE_OPTION_WINDOW_PU_C3;
		   xvt_win_dispatch_event (xdWindow, xdEvent);
		}
		/* TAG END EVNT:Char */
		}
		break;
	case E_MOUSE_UP:
		/*
			Mouse was released
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Up */
		/* TAG END EVNT:Mouse_Up */
		}
		break;
	case E_MOUSE_DOWN:
		/*
			Mouse was pressed
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Down */
		/* TAG END EVNT:Mouse_Down */
		}
		break;
	case E_MOUSE_DBL:
		/*
			Mouse was double clicked
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Dbl */
		/* TAG END EVNT:Mouse_Dbl */
		}
		break;
	case E_MOUSE_MOVE:
		/*
			Mouse was moved
		*/
		{
		/* TAG BEGIN EVNT:Mouse_Move */
		/* TAG END EVNT:Mouse_Move */
		}
		break;
	case E_HSCROLL:
		{
		/* TAG BEGIN EVNT:Hscroll */
		/*
			Horizontal scrollbar on frame was operated
		*/
		switch (xdEvent->v.scroll.what) {
		case SC_LINE_UP:
			break;
		case SC_LINE_DOWN:
			break;
		case SC_PAGE_UP:
			break;
		case SC_PAGE_DOWN:
			break;
		case SC_THUMB:
			break;
		case SC_THUMBTRACK:
			break;
		default:
			break;
		}
		/* TAG END EVNT:Hscroll */
		}
		break;
	case E_VSCROLL:
		{
		/* TAG BEGIN EVNT:Vscroll */
		/*
			Vertical scrollbar on frame was operated
		*/
		switch (xdEvent->v.scroll.what) {
		case SC_LINE_UP:
			break;
		case SC_LINE_DOWN:
			break;
		case SC_PAGE_UP:
			break;
		case SC_PAGE_DOWN:
			break;
		case SC_THUMB:
			break;
		case SC_THUMBTRACK:
			break;
		default:
			break;
		}
		/* TAG END EVNT:Vscroll */
		}
		break;
	case E_COMMAND:
		/*
			User issued command on window menu bar (menu bar at top of
			screen for Mac/CH).
		*/
		{
		/* TAG BEGIN EVNT:Command */
		/*
			No menubar was associated with this window
		*/
		/* TAG END EVNT:Command */
		}
		break;
	case E_CONTROL:
		/*
			User operated control in window.
		*/
		{
		/* TAG BEGIN SPCL:Control_Decl */
		/* TAG END SPCL:Control_Decl */

		switch(xdControlId) {
		case IMAGE_RANGE_MAX: /* "max" */
			{
			/* TAG BEGIN IMAGE_RANGE_MAX EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/*
					Contents of control were changed
				*/
			updateScrollAndText (xdWindow, IMAGE_RANGE_MAX_BAR, IMAGE_RANGE_MAX, FALSE);
			updateGeophysicsImageOptions (xdWindow);
			}
			/* TAG END IMAGE_RANGE_MAX EVNT:Control */
			}
			break;
		case IMAGE_RANGE_MIN: /* "min" */
			{
			/* TAG BEGIN IMAGE_RANGE_MIN EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/*
					Contents of control were changed
				*/
			updateScrollAndText (xdWindow, IMAGE_RANGE_MIN_BAR, IMAGE_RANGE_MIN, FALSE);
			updateGeophysicsImageOptions (xdWindow);
			}
			/* TAG END IMAGE_RANGE_MIN EVNT:Control */
			}
			break;
		case IMAGE_RANGE_MAX_BAR: /* "Range Max Bar" */
			{
			/* TAG BEGIN IMAGE_RANGE_MAX_BAR EVNT:Control */
			int pos = 0;
			/*
				Horizontal scrollbar control was operated
			*/
			switch (xdEvent->v.ctl.ci.v.scroll.what) {
			case SC_LINE_UP:
				pos = xvt_sbar_get_pos (xdEvent->v.ctl.ci.win, HVSCROLL) - 1;
				break;
			case SC_LINE_DOWN:
				pos = xvt_sbar_get_pos (xdEvent->v.ctl.ci.win, HVSCROLL) + 1;
				break;
			case SC_PAGE_UP:
				pos = xvt_sbar_get_pos (xdEvent->v.ctl.ci.win, HVSCROLL) - TEN;
				SNAP_DOWN_BY(pos,10)
				break;
			case SC_PAGE_DOWN:
				pos = xvt_sbar_get_pos (xdEvent->v.ctl.ci.win, HVSCROLL) + TEN;
				SNAP_UP_BY(pos,10)
				break;
			case SC_THUMB:
				pos = xdEvent->v.ctl.ci.v.scroll.pos;
				break;
			case SC_THUMBTRACK:
				pos = xdEvent->v.ctl.ci.v.scroll.pos;
				break;
			}
			pos = updateScrollField (xdWindow, xdControlId, pos);
			updateNumericTextField (xdWindow, IMAGE_RANGE_MAX, pos);
			updateGeophysicsImageOptions (xdWindow);
			/* TAG END IMAGE_RANGE_MAX_BAR EVNT:Control */
			}
			break;
		case IMAGE_RANGE_MIN_BAR: /* "Range Min Bar" */
			{
			/* TAG BEGIN IMAGE_RANGE_MIN_BAR EVNT:Control */
			int pos = 0;
			/*
				Horizontal scrollbar control was operated
			*/
			switch (xdEvent->v.ctl.ci.v.scroll.what) {
			case SC_LINE_UP:
				pos = xvt_sbar_get_pos (xdEvent->v.ctl.ci.win, HVSCROLL) - 1;
				break;
			case SC_LINE_DOWN:
				pos = xvt_sbar_get_pos (xdEvent->v.ctl.ci.win, HVSCROLL) + 1;
				break;
			case SC_PAGE_UP:
				pos = xvt_sbar_get_pos (xdEvent->v.ctl.ci.win, HVSCROLL) - TEN;
				SNAP_DOWN_BY(pos, 10)
				break;
			case SC_PAGE_DOWN:
				pos = xvt_sbar_get_pos (xdEvent->v.ctl.ci.win, HVSCROLL) + TEN;
				SNAP_UP_BY(pos, 10)
				break;
			case SC_THUMB:
				pos = xdEvent->v.ctl.ci.v.scroll.pos;
				break;
			case SC_THUMBTRACK:
				pos = xdEvent->v.ctl.ci.v.scroll.pos;
				break;
			}
			pos = updateScrollField (xdWindow, xdControlId, pos);
			updateNumericTextField (xdWindow, IMAGE_RANGE_MIN, pos);
			updateGeophysicsImageOptions (xdWindow);
			/* TAG END IMAGE_RANGE_MIN_BAR EVNT:Control */
			}
			break;
		case IMAGE_OPTION_WINDOW_PU_C3: /* "OK" */
			{
			/* TAG BEGIN IMAGE_OPTION_WINDOW_PU_C3 EVNT:Control */
			int contourImage = xvt_ctl_is_checked (xvt_win_get_ctl (xdWindow, IMAGE_LUT_CONTOUR));
			saveGeophysicsImageOptions (xdWindow);
			
			/* TAG END IMAGE_OPTION_WINDOW_PU_C3 EVNT:Control */
			}
			break;
		case IMAGE_OPTION_WINDOW_PU_C4: /* "Cancel" */
			{
			/* TAG BEGIN IMAGE_OPTION_WINDOW_PU_C4 EVNT:Control */
			xvt_vobj_destroy(xdWindow);
			/* TAG END IMAGE_OPTION_WINDOW_PU_C4 EVNT:Control */
			}
			break;
		case IMAGE_OPTION_WINDOW_PU_C5: /* "Help..." */
			{
			/* TAG BEGIN IMAGE_OPTION_WINDOW_PU_C5 EVNT:Control */
			displayEventHelp ((OBJECT *) xvt_vobj_get_data (xdWindow));
			/* TAG END IMAGE_OPTION_WINDOW_PU_C5 EVNT:Control */
			}
			break;
		case IMAGE_LUT_GREY: /* "Grey Scale" */
			{
			/* TAG BEGIN IMAGE_LUT_GREY EVNT:Control */
			xdCheckRadioButton(xdWindow, IMAGE_LUT_GREY,
				IMAGE_LUT_GREY, IMAGE_LUT_CONTOUR);
			updateGeophysicsImageOptions (xdWindow);
			/* TAG END IMAGE_LUT_GREY EVNT:Control */
			}
			break;
		case IMAGE_LUT_PSEUDO: /* "Pseudo Color" */
			{
			/* TAG BEGIN IMAGE_LUT_PSEUDO EVNT:Control */
			xdCheckRadioButton(xdWindow, IMAGE_LUT_PSEUDO,
				IMAGE_LUT_GREY, IMAGE_LUT_CONTOUR);
			updateGeophysicsImageOptions (xdWindow);
			/* TAG END IMAGE_LUT_PSEUDO EVNT:Control */
			}
			break;
		case IMAGE_LUT_CONTOUR: /* "Contour" */
			{
			/* TAG BEGIN IMAGE_LUT_CONTOUR EVNT:Control */
			xdCheckRadioButton(xdWindow, IMAGE_LUT_CONTOUR,
				IMAGE_LUT_GREY, IMAGE_LUT_CONTOUR);
			updateGeophysicsImageOptions (xdWindow);
			/* TAG END IMAGE_LUT_CONTOUR EVNT:Control */
			}
			break;
		case IMAGE_NUM_CONTOUR: /* "numContour" */
			{
			/* TAG BEGIN IMAGE_NUM_CONTOUR EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/*
					Contents of control were changed
				*/
			      int numContours;
			                          /* Range Check for the number of contours */
			      numContours = getIntegerTextFieldValue (xdWindow, IMAGE_NUM_CONTOUR);
			      if (numContours < 1)
			      {
			         numContours = 1;
			         updateNumericTextField (xdWindow, IMAGE_NUM_CONTOUR, numContours);
			      }
			      if (numContours > 50)
			      {
			         numContours = 50;
			         updateNumericTextField (xdWindow, IMAGE_NUM_CONTOUR, numContours);
			      }
			}
			/* TAG END IMAGE_NUM_CONTOUR EVNT:Control */
			}
			break;
		case IMAGE_CLIPPING_TYPE: /* "clip type" */
			{
			/* TAG BEGIN IMAGE_CLIPPING_TYPE EVNT:Control */
			updateGeophysicsImageOptions (xdWindow);
			/* TAG END IMAGE_CLIPPING_TYPE EVNT:Control */
			}
			break;
		case IMAGE_GRID: /* "Grid Overlay" */
			{
			/* TAG BEGIN IMAGE_GRID EVNT:Control */
			WINDOW ctl_win = xvt_win_get_ctl(xdWindow, IMAGE_GRID);
			xvt_ctl_set_checked(ctl_win, !xvt_ctl_is_checked(ctl_win));
			updateGeophysicsImageOptions (xdWindow);
			/* TAG END IMAGE_GRID EVNT:Control */
			}
			break;
		case IMAGE_GRID_XSTART: /* "x" */
			{
			/* TAG BEGIN IMAGE_GRID_XSTART EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END IMAGE_GRID_XSTART EVNT:Control */
			}
			break;
		case IMAGE_GRID_YSTART: /* "y" */
			{
			/* TAG BEGIN IMAGE_GRID_YSTART EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END IMAGE_GRID_YSTART EVNT:Control */
			}
			break;
		case IMAGE_GRID_XINC: /* "xinc" */
			{
			/* TAG BEGIN IMAGE_GRID_XINC EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END IMAGE_GRID_XINC EVNT:Control */
			}
			break;
		case IMAGE_GRID_YINC: /* "yinc" */
			{
			/* TAG BEGIN IMAGE_GRID_YINC EVNT:Control */
			/*
				Edit control was operated.
			*/
			if (xdEvent->v.ctl.ci.v.edit.focus_change) {
				if (xdEvent->v.ctl.ci.v.edit.active) {
					/*
						focus has entered the control
					*/
				} else {
					/*
						focus has left the control
					*/
				}
			} else {
				/* 
					Contents of control were changed
				*/
			}
			/* TAG END IMAGE_GRID_YINC EVNT:Control */
			}
			break;
		case IMAGE_GRID_AUTO: /* "Auto" */
			{
			/* TAG BEGIN IMAGE_GRID_AUTO EVNT:Control */
			WINDOW ctl_win = xvt_win_get_ctl(xdWindow, IMAGE_GRID_AUTO);
			xvt_ctl_set_checked(ctl_win, !xvt_ctl_is_checked(ctl_win));
			updateGeophysicsImageOptions (xdWindow);
			/* TAG END IMAGE_GRID_AUTO EVNT:Control */
			}
			break;
		case IMAGE_GRID_SENSOR: /* "Sensor" */
			{
			/* TAG BEGIN IMAGE_GRID_SENSOR EVNT:Control */
			WINDOW ctl_win = xvt_win_get_ctl(xdWindow, IMAGE_GRID_SENSOR);
			xvt_ctl_set_checked(ctl_win, !xvt_ctl_is_checked(ctl_win));
			/* TAG END IMAGE_GRID_SENSOR EVNT:Control */
			}
			break;
		default:
			break;
		}
		}
		break;
	case E_FONT:
		/*
			User issued font command on window menu bar (menu bar at top of
			screen for Mac/CH).
		*/
		{
		/* TAG BEGIN EVNT:Font */
		/* TAG END EVNT:Font */
		}
		break;
	case E_TIMER:
		/*
			Timer associated with window went off.
		*/
		{
		/* TAG BEGIN EVNT:Timer */
		/* TAG END EVNT:Timer */
		}
		break;
	case E_USER:
		/*
			Application initiated.
		*/
		{
		/* TAG BEGIN EVNT:User */
		switch (xdEvent->v.user.id) {
		case -1:
		default:
			break;
		}
		/* TAG END EVNT:User */
		}
		break;
	default:
		break;
	}
	/* TAG BEGIN SPCL:Bottom */
#ifdef XVT_R40_TXEDIT_BEHAVIOR
	xvt_tx_process_event(xdWindow, xdEvent);
#endif
	/* TAG END SPCL:Bottom */
	return 0L;
}
