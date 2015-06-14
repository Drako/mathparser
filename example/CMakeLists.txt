ADD_DEFINITIONS ( ${CXX11_DEFINES} )

INCLUDE_DIRECTORIES ( ../mathparser )
ADD_EXECUTABLE ( parsemath main.cxx )
TARGET_LINK_LIBRARIES ( parsemath mathparser )

INSTALL ( TARGETS parsemath DESTINATION bin )

