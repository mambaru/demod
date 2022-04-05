#include "demod_build_info.h"

#include <wfc/wfc.hpp>
#include <wfcroot/wfcroot.hpp>

int main(int argc, char* argv[])
{
  return wfc::wfc<demod_build_info>( wfc::wfcroot({})).run(argc, argv, "WFCROOT educational project");
}
