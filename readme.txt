This is the batch (and function) version of Noddy that simply takes a history file and calculates a block model, triangulated volume and gravity and magnetic data from this file.

Usage:

noddy input_history  output_prefix

It will generate a *.g00 file (block model header); a *.g12 file (block model itself) and a *.dxf file (triangulated surfaces)

WARNING: This version will crash if the history file is not set to create either of the two types of DXF triangulations (DXF 3D faces or DXF polylines) rather than Lines, Shading, or Vulcan file. In the history file this should read 

#3DOptions
.
.
.
	Fill Type	= 3
	
The resulting DXF file has each surface (and triangle) coded according to the following information-
For discontinuities (coded as faults=1,  unconformities=2, dykes=4, plugs=8, stratigraphic=16): age of discontinuity, code of discontinuity ,contiguous volume code #1, contiguous volume code #2,rock #1 adjacent to triangle,rock #2 adjacent to triangle 
For stratigraphic surfaces: stratigraphic series code, unit in series, lithological code, rock #1 adjacent to triangle,rock #2 adjacent to triangle 

This code is open source blah blah blah...

Use with care, I haven't tested this particular version of the grav/mag calcs to see if they are correct, but they seem to be...

Code developed by Mark Jessell, Paul Manser, and Sue Farrell
