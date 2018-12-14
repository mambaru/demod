#include "demod_build_info.h"

#include <wfc/wfc.hpp>
#include <wfcroot/wfcroot.hpp>
#include <wfc_demo/package/demo_package.hpp>

int main(int argc, char* argv[])
{
  return ::wfc::wfc<demod_build_info>( ::wfc::wfcroot(
    {
      std::make_shared< demo::demo_package >()
    }
  )).run(argc, argv, "Educational project");
}
