
#include <wonderwaffel/wonderwaffel.hpp>
#include <hash/api/get_hash_json.hpp>
#include <package/demo_package.hpp>
#include <hash/ihash.hpp>
#include <wfc/name.hpp>
#include "wonderwaffel0_build_info.h"

WFC_NAME2(method_get_hash, "method-get_hash")

int main(int argc, char* argv[])
{
  wfc::wonderwaffel<wonderwaffel0_build_info> ww;
  ww.add_package<damba::demo_package>();
  {
    using namespace damba::hash;
    ww.add_tank<method_get_hash, request::get_hash_json, response::get_hash_json>(&ihash::get_hash);
  }
  ww.run(argc, argv, "Вундервафля для обстрела демона demod методом get_hash");
}
