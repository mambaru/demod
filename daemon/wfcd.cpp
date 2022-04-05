#include "demod_build_info.h"

#include <wfc/wfc.hpp>

int main(int argc, char* argv[])
{
  return wfc::wfc<demod_build_info>({}).run(argc, argv, "Empty WFC educational project");
}
