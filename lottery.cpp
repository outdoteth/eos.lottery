#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/action.hpp>
#include <eosiolib/currency.hpp>
#include <eosiolib/multi_index.hpp>
#include <eosiolib/vector.hpp>
#include <eosiolib/action.hpp>
#include <string>

using namespace eosio;

namespace eosiosystem {
   class system_contract;
}

class lottery : public contract {

public:
	lottery( account_name self ) : contract(self){}

	//@abi table tickets
	struct ticket {
		account_name player;
		uint64_t starting_ticket_id;
		uint64_t primary_key() const { return starting_ticket_id; }
	};

	struct currentround {
		asset pot_reward;
		uint64_t time_started;
		asset fee_reward;
	};

	typedef eosio::multi_index< N(tickets), ticket > tickets;

	void makebet( asset amount, account_name player );
	void submithash();
	void submitsecret();
	void calculatewinner();	
};


void lottery::makebet( asset amount, account_name player)
{
	
}
 
extern "C" {

    /// The apply method implements the dispatch of events to this contract
    void apply( uint64_t receiver, uint64_t code, uint64_t action ) {
      if( code == N(eosio) && action == N(onerror) ) {
         //apply_onerror( receiver, onerror::from_current_action() );
      } else if( code ) {
      		switch(action) {

      		}
      }
   }
}


