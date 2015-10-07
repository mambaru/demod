#include "demod_build_info.h"

#include <wfc/wfc.hpp>
#include <wfcroot/wfcroot.hpp>
#include <wfc_demo/demo/demo_package.hpp>

struct my_build_info: demod_build_info
{
  std::string version() const { return "1.0"; } 
};

int main(int argc, char* argv[])
{
  
  
  return ::wfc::wfc(
    ::wfc::make_build_info<my_build_info>(), 
    ::wfc::wfcroot({
      std::make_shared< ::wamba::demo_package >()
    })
  ).run(argc, argv);
}
