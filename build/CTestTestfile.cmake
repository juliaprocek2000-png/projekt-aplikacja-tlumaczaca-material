# CMake generated Testfile for 
# Source directory: C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material
# Build directory: C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(OllamaConnectionTest "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/build/Debug/UnitTests.exe")
  set_tests_properties(OllamaConnectionTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/CMakeLists.txt;66;add_test;C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(OllamaConnectionTest "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/build/Release/UnitTests.exe")
  set_tests_properties(OllamaConnectionTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/CMakeLists.txt;66;add_test;C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(OllamaConnectionTest "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/build/MinSizeRel/UnitTests.exe")
  set_tests_properties(OllamaConnectionTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/CMakeLists.txt;66;add_test;C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(OllamaConnectionTest "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/build/RelWithDebInfo/UnitTests.exe")
  set_tests_properties(OllamaConnectionTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/CMakeLists.txt;66;add_test;C:/Users/Julia/Desktop/projekt-aplikacja-tlumaczaca-material/CMakeLists.txt;0;")
else()
  add_test(OllamaConnectionTest NOT_AVAILABLE)
endif()
