#pragma once

/*
#include <wfcroot/wfcroot.hpp>
#include <wfc/wfc.hpp>

#include <wfc/name.hpp>
#include <wfc/domain_object.hpp>
#include <wjson/wjson.hpp>
#include <wfc/module/module_list.hpp>
#include <wfc/module/component_list.hpp>
#include <wfc/module/multiton.hpp>
#include <wfc/module/instance.hpp>
#include <demo/idemo.hpp>
#include <package/demo_package.hpp>
#include <fas/utility/ignore_args.hpp>

namespace wfc
{

template<
  typename O = fas::empty_type,
  typename Req = fas::empty_type,
  typename Res = fas::empty_type
>
struct tank_options: O
{
  std::string target;
  Req request;
  Res response;
};

template<typename T = fas::empty_type>
struct empty_json
{
  typedef wjson::object<T, wjson::member_list< > > type;
  typedef typename type::serializer serializer;
  typedef typename type::target target;
  typedef typename type::member_list member_list;
};


template< typename OJ = empty_json<>, typename ReqJ = empty_json<>, typename ResJ = empty_json<> >
struct tank_options_json
{
  JSON_NAME(request)
  JSON_NAME(response)
  typedef typename OJ::target base_options;
  typedef typename ReqJ::target request_options;
  typedef typename ResJ::target response_options;
  typedef tank_options<base_options, request_options, response_options> options_type;
  JSON_NAME(target)
  typedef wjson::object<
    options_type,
    wjson::member_list<
      wjson::member<n_target, options_type, std::string, &options_type::target>,
      wjson::member<n_request, options_type, request_options, &options_type::request, ReqJ>,
      wjson::member<n_response, options_type, response_options, &options_type::response, ResJ>,
      wjson::base<OJ>
    >
  > type;
  typedef typename type::serializer serializer;
  typedef typename type::target target;
  typedef typename type::member_list member_list;
};

template<typename O = fas::empty_type>
class waffel_domain
  : public domain_object<iinterface, O>
{
};


template<
  typename O = fas::empty_type,
  typename Req = fas::empty_type,
  typename Res = fas::empty_type
>
class waffel_tank
  : public waffel_domain<tank_options<O, Req, Res> >
{
};

template<typename Name, typename DomainObject, typename J = empty_json<typename DomainObject::options_type> >
class waffel_package: public module_list<
              named_build_info<Name>,
              component_list<
                Name,
                multiton<
                  Name,
                  instance< DomainObject >,
                  J
                >
              >
            >
{
};


template<typename I, typename Req, typename Res >
class tank_gun: public iinterface
{
public:
  typedef std::unique_ptr<Req> req_t;
  typedef std::unique_ptr<Res> res_t;
  typedef std::function< void(res_t) >  handler_t;
  typedef void (I::* target_method)(req_t, handler_t);
  
  tank_gun(
    target_method tm, 
    std::function<bool(Req*)> req_gen,
    std::function<bool(Res*)> res_check
  )
    : _target_method(tm)
    , _req_gen(req_gen)
    , _res_check(res_check)
  {}
  
  virtual void bang(const std::shared_ptr<I>& target, req_t req, handler_t cb)
  {
    (target.get()->*_target_method)(std::move(req), cb);
  }
private:
  target_method _target_method;
  std::function<bool(Req*)> _req_gen;
  std::function<bool(Res*)> _res_check;
};

template<typename Name, typename I, typename ReqJson, typename ResJson>
class tank_package
  : public waffel_package<Name, waffel_tank<fas::empty_type, typename ReqJson::target, typename ResJson::target>, tank_options_json< empty_json<>, ReqJson, ResJson > >
{
  typedef waffel_package<Name, waffel_tank<fas::empty_type, typename ReqJson::target, typename ResJson::target>, tank_options_json< empty_json<>, ReqJson, ResJson > > super;
public: 
  typedef void (I::* target_method)(std::unique_ptr<typename ReqJson::target>,std::function< void(std::unique_ptr<typename ResJson::target>) >);
  typedef tank_gun<I, typename ReqJson::target, typename ResJson::target> tank_gun_t;
  typedef std::shared_ptr<tank_gun_t> tank_gun_ptr;
  
  tank_package(
    target_method tm, 
    std::function<bool(typename ReqJson::target*)> req_gen, 
    std::function<bool(typename ResJson::target*)> res_check
  ) : _tank_gun( std::make_shared<tank_gun_t>(tm, req_gen, res_check))
  {
  }

  virtual void create( std::shared_ptr<wfcglobal> g) override
  {
    super::waffel_package::create(g);
    //void set_object(const std::string& prefix, const std::string& name, std::shared_ptr<iinterface> item, bool nomark = false );
    g->registry.set_object("wonderwaffel", Name()(), _tank_gun, true);
  }
private:
  tank_gun_ptr _tank_gun;
};


template<typename Req>
bool request_gen_def(Req*)
{
  return true;
}

template<typename Res>
bool response_check_def(Res*)
{
  return true;
}

class wonderwaffel
{
public:
  template<typename T>
  void add_package()
  {
    _packages.push_back( std::make_shared<T>() );
  }

  template<typename N, typename T>
  void add_object()
  {
    typedef waffel_package<N, T> package_type;
    _packages.push_back( std::make_shared<package_type>() );
  }

  template<typename N, typename ReqJson, typename ResJson, typename I>
  void add_tank( 
    void (I::* mem_ptr)(std::unique_ptr<typename ReqJson::target>,std::function< void(std::unique_ptr<typename ResJson::target>) >),
    std::function<bool(typename ReqJson::target*)> req_gen = request_gen_def<typename ReqJson::target>,
    std::function<bool(typename ResJson::target*)> res_check = response_check_def<typename ResJson::target>
  )
  {
    auto ptank = std::make_shared< tank_package<N, I, ReqJson, ResJson> >(mem_ptr, req_gen, res_check);
    _packages.push_back(ptank);
  }

  int run(int argc, char* argv[], std::string helpstring = std::string() )
  {
    return wfc<empty_build_info>(wfcroot(_packages)).run(argc, argv, helpstring);
  }


private:

private:
  std::list< std::shared_ptr<ipackage> > _packages;
};

}
*/
