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

This code is open source blah blah blah...

Use with care, I haven't tested this particular version of the grav/mag calcs to see if they are correct, but they seem to be...

Code developed by Mark Jessell, Paul Manser, and Sue Farrell
