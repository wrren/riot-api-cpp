#include <riot/riot.h>

namespace riot
{
	riot_client::riot_client( region_t region, const api_key_t& key, const riot_client::options_t options ) :
	m_options( options ),
	m_region( region ),
	m_key( key ),
	m_summoner( this ),
	m_team( this ),
	m_match( this ),
	m_games( this )
	{}

	const summoner_retriever& riot_client::summoner() const
	{
		return m_summoner;
	}

	const team_retriever& riot_client::team() const 
	{ 
		return m_team; 
	}

	const match_retriever& riot_client::match() const 
	{ 
		return m_match; 
	}

	const game_retriever& riot_client::games() const 
	{ 
		return m_games; 
	}

	const region_t riot_client::region() const 
	{ 
		return m_region; 
	}

	const api_key_t& riot_client::key() const 
	{ 
		return m_key; 
	}

	const riot_client::options_t& riot_client::options() const
	{ 
		return m_options; 
	}
}