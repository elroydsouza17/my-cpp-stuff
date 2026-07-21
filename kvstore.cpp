/*********** Basic DB using classes ********************/
#include <iostream>
#include <string>
#include <map>
#include <optional>

class KVStore 
{

    public: 
        void put(const std::string& key, const std::string& val)
        {
            data_[key] = val;
        }

        std::optional<std::string> get(const std::string& key)
        {
            auto keyVal = data_.find(key);
            if(keyVal == data_.end())
            {
                return std::nullopt;    
            }
            
            return keyVal->second ;
        }

        bool del(const std::string& key)
        {
            auto val = data_.erase(key);
            if(val) 
            {
                return true;
            }
            else
            {
                return false;
            }
        } 

    private: 
        std::map <std::string, std::string> data_;  
};

int main()
{
    KVStore kv;
    kv.put("1", "elroy");
    kv.put("2", "elisha");
    auto isDeleted = kv.del("3");
    auto value = kv.get("1");
    

    if(value)
    {
        std::cout << *value << std::endl;
    } else 
    {
        std::cout << "key not found" << std::endl;
    }

    if(isDeleted)
    {
        std::cout << "key is deleted" << std::endl;
    } else 
    {
        std::cout << "key not found hence not deleted" << std::endl;
    }
    
}


