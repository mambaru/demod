#include <wonderwaffel/wonderwaffel.hpp>
#include <wfc/name.hpp>
#include <demo/api/get_json.hpp>
#include <demo/idemo.hpp>
#include <package/demo_package.hpp>


struct demo_waffel_options{};

class demo_waffel_domain
  : public wfc::domain_object<wfc::iinterface, demo_waffel_options>
{
public:
  virtual void start() override
  {
  }
};

WFC_NAME(demo_waffel)
WFC_NAME2(tank_demo_get, "tank_demo_get")

int main(int argc, char* argv[])
{
  wfc::wonderwaffel ww;
  ww.add_package<demo::demo_package>();
  ww.add_object<n_demo_waffel, demo_waffel_domain>();
  ww.add_tank<tank_demo_get, demo::request::get_json, demo::response::get_json, wjson::empty_object<> >(&demo::istorage::get);
  ww.add_tank<tank_demo_get>(&demo::istorage::get);
  //ww.add_tank<tank_demo_get, demo::request::get_json, demo::response::get_json, wjson::empty_object<> >(&demo::istorage::get);
  ww.run(argc, argv,"Вундервафля для обстрела demo storage");
}
