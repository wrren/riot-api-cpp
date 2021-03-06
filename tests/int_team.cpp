#include <riot/riot.h>
#include "int_key.h"

using namespace riot;

TEST_CASE( "Retrieve Teams", "[dto]" )
{
	riot_client client( region_t::EUW, int_key::get_key() );

	SECTION( "Get Team List" )
	{
		auto res = client.summoner().by_name( { "General Atomic" } );
		REQUIRE( res.size() != 0 );

		auto teams = client.team().by_summoner( { res[0] } );
		REQUIRE( teams.size() != 0 );

		teams = client.team().by_id( { teams[0].id } );
		REQUIRE( teams.size() != 0 );
	}
}