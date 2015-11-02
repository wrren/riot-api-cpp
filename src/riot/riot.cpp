#include <riot/riot.h>

namespace riot
{
	riot_client::riot_client( region_t region, const api_key_t& key ) :
	m_region( region ),
	m_key( key ),
	m_summoner( region, key ),
	m_team( region, key )
	{}
}