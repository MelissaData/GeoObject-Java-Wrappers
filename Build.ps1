# Set Java Includes and Geo Object Library Path
$JavaIncludeDirectory1 = "C:\Program Files\Java\jdk-20\include"
$JavaIncludeDirectory2 = "C:\Program Files\Java\jdk-20\include\win32"
$GeoLibraryPath = $PSScriptRoot

# Run cl command
& 'cl' -I"$GeoLibraryPath" -I"$JavaIncludeDirectory1" -I"$JavaIncludeDirectory2" -Fe'mdGeoJavaWrapper.dll' 'mdGeoJavaWrapper.cpp' -link -DLL -LIBPATH:"$GeoLibraryPath" -DEFAULTLIB:'mdGeo.lib'

# Remove files
Remove-Item 'mdGeoJavaWrapper.exp' -ErrorAction SilentlyContinue
Remove-Item 'mdGeoJavaWrapper.obj' -ErrorAction SilentlyContinue
Remove-Item 'mdGeoJavaWrapper.lib' -ErrorAction SilentlyContinue

