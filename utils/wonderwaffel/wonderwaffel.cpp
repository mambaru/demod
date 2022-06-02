
#include <package/demo_package.hpp>
#include <hash/ihash.hpp>
#include <hash/api/get_hash_json.hpp>
#include <wfc/name.hpp>
#include <wonderwaffel/wonderwaffel.hpp>
#include "wonderwaffel1_build_info.h"

namespace{

  using namespace damba::hash;
  bool gen_get_hash(request::get_hash&,  response::get_hash&)
  {
    return true;
  }

  bool check_get_hash(const request::get_hash&, const response::get_hash&, const response::get_hash&)
  {
    return true;
  }

}

WFC_NAME2(method_get_hash0, "method-get_hash0")
WFC_NAME2(method_get_hash1, "method-get_hash1")
WFC_NAME2(method_get_hash2, "method-get_hash2")

int main(int argc, char* argv[])
{
  wfc::wonderwaffel<wonderwaffel1_build_info> ww;
  ww.add_package<damba::demo_package>();
  {
    using namespace damba::hash;
    ww.add_tank<method_get_hash0, request::get_hash_json, response::get_hash_json>(&ihash::get_hash);
    ww.add_tank<method_get_hash1, request::get_hash_json, response::get_hash_json>(&ihash::get_hash, gen_get_hash);
    ww.add_tank<method_get_hash2, request::get_hash_json, response::get_hash_json>(&ihash::get_hash, gen_get_hash, check_get_hash);
  }
  ww.run(argc, argv, "Вундервафля для обстрела demo storage");
}
