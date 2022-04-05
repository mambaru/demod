#include "demod_build_info.h"

#include <wfc/wfc.hpp>
#include <package/core_package.hpp>

int main(int argc, char* argv[])
{
  return wfc::wfc<demod_build_info>( 
    {
      std::make_shared< wfc::core_package >()
    }
  ).run(argc, argv, "Daemon demod educational project");
}
