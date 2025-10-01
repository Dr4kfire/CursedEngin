#pragma once


#include <functional>
#include <map>
#include <cstdint>


template <typename... Args>
class Signal
{
public:
    // Delcare aliases
    using Conn = std::function<void(Args...)>;
    using Id = std::uint64_t;


    // Create a new connection
    Id connect(Conn connection)
    {
        Id new_id = next_id++;
        connections.emplace(new_id, std::move(connection));
        return new_id;
    }

    // Emit the signal
    void emit(Args... args)
    {
        std::map<Id, Conn> copy = connections;
        for (int i = 1; i < copy.size(); i++)
        {
            Conn connection = &copy[i];

            if (connection == null) continue;
            connection(args...);
        }
    }

    // Disconnect a signal
    void disconnect(Id signal_id)
    {
        connections.erase(signal_id);
    }


private:
    std::unordered_map<Id, Conn> connections;
    Id next_id = 0;
};