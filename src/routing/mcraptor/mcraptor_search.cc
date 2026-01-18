#include "../nigiri/include/nigiri/routing/mcraptor/mcraptor_search.h"

#include <string>
#include <utility>
#include "date/date.h"
#include "utl/to_vec.h"
#include "nigiri/routing/mcraptor/mcraptor.h"


namespace nigiri::routing {

template <direction SearchDir>
routing_result mcraptor_search(
    timetable const& tt,
    rt_timetable const* rtt,
    search_state& s_state,
    raptor_state& r_state,
    query q,
    std::optional<std::chrono::seconds> const timeout) {
//  if (rtt != nullptr) {
//    return {};
//  }

  using algo_t = mcraptor<SearchDir>;
  return search<SearchDir, algo_t>{
      tt, rtt, s_state,r_state, std::move(q), timeout}
        .execute();
}


template routing_result mcraptor_search<direction::kForward>(
    timetable const&, rt_timetable const*, search_state&, raptor_state&,
    query, std::optional<std::chrono::seconds>);

template routing_result mcraptor_search<direction::kBackward>(
    timetable const&, rt_timetable const*, search_state&, raptor_state&,
    query, std::optional<std::chrono::seconds>);

}  // namespace nigiri::routing