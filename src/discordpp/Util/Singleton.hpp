/**
 * @file Singleton.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-03-19 11:36
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <assert.h>

namespace discordpp
{

template <typename T>
class Singleton
{
  public:
    /**
			* Creates a Singleton instance of a specific Type
			*@return true if instance was created, false if instance was already instantiated
			*/
    static bool create()
    {
        if (Singleton::m_instance != nullptr)
            return false;

        Singleton::m_instance = new T();
        return true;
    }
    /**
			* Creates a Singleton instance of a specific with a specified Pointer 
			* @param Pointer that the Singleton should use to be instantiated
			* @return true if instance was created, false if instance was already instantiated
			*/
    static bool create(T *in)
    {

        if (Singleton::m_instance != nullptr)
            return false;

        Singleton::m_instance = in;
        return true;
    }
    /**
			*Gets the Singleton pointer with the specific Type
			@return T* The singleton to be returned
			*/
    static T *get()
    {
        assert(Singleton::m_instance != nullptr);
        return Singleton::m_instance;
    }

    /**
			* Tries to destroy the Singleton instance if it was already instantiated
			* @return true if instance was destroyed, false if instance hasn't even been instantiated
			*/
    static bool destroy()
    {
        if (Singleton::m_instance == nullptr)
            return false;

        delete Singleton::m_instance;
        return true;
    }

  private:
    static T *m_instance; /** Pointer of Singleton instance */
    Singleton()
    {
    }
    ~Singleton() {}
    Singleton(Singleton const &) = delete;
    Singleton &operator=(Singleton const &) = delete;
    Singleton(Singleton const &&) = delete;
    Singleton &operator=(Singleton const &&) = delete;
};

template <typename T>
T *Singleton<T>::m_instance = nullptr;

} // namespace discordpp

#endif