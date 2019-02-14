/**
 * @file Gateway.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-01 02:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Gateway.hpp"

#include <sstream>

#include "Bot.hpp"
#include "constants.hpp"

namespace discordpp
{
Gateway::Gateway(Bot *bot)
{
    m_pBot = bot;

    m_endpoint.set_access_channels(websocketpp::log::alevel::none);
    m_endpoint.set_error_channels(websocketpp::log::elevel::all);

    // Initialize ASIO
    m_endpoint.init_asio();

    // Register our handlers
    m_endpoint.set_socket_init_handler(bind(&Gateway::on_socket_init, this, ::_1));
    m_endpoint.set_tls_init_handler(bind(&Gateway::on_tls_init, this, ::_1));
    m_endpoint.set_message_handler(bind(&Gateway::on_message, this, ::_1, ::_2));
    m_endpoint.set_open_handler(bind(&Gateway::on_open, this, ::_1));
    m_endpoint.set_close_handler(bind(&Gateway::on_close, this, ::_1));
    m_endpoint.set_fail_handler(bind(&Gateway::on_fail, this, ::_1));

    DEBUG("Gateway constructed");
}

Gateway::~Gateway()
{
}

void Gateway::connect()
{
    websocketpp::lib::error_code ec;
    client::connection_ptr con = m_endpoint.get_connection(constants::websocketuri, ec);

    DEBUG("Gateway Connection getted");
    if (ec)
    {
        m_endpoint.get_alog().write(websocketpp::log::alevel::app, ec.message());
        return;
    }

    m_endpoint.connect(con);
    DEBUG("Connected");

    // Start the ASIO io_service run loop
    m_endpoint.run();
}
websocketpp::connection_hdl &Gateway::getHandle()
{
    return m_hdl;
}

client &Gateway::getEndpoint()
{
    return m_endpoint;
}

void Gateway::on_socket_init(const websocketpp::connection_hdl &hdl)
{
    DEBUG("Gateway::onSocketInit");
}

context_ptr Gateway::on_tls_init(const websocketpp::connection_hdl &hdl)
{
    DEBUG("Gateway::onTlsInit");
    context_ptr ctx = websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv1);

    try
    {
        ctx->set_options(boost::asio::ssl::context::tlsv1_client);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return ctx;
}

void Gateway::on_fail(const websocketpp::connection_hdl &hdl)
{
    DEBUG("Gateway::onFail");
    client::connection_ptr con = m_endpoint.get_con_from_hdl(hdl);

    std::cerr << "Fail handler" << std::endl;
    std::cerr << con->get_state() << std::endl;
    std::cerr << con->get_local_close_code() << std::endl;
    std::cerr << con->get_local_close_reason() << std::endl;
    std::cerr << con->get_remote_close_code() << std::endl;
    std::cerr << con->get_remote_close_reason() << std::endl;
    std::cerr << con->get_ec() << " - " << con->get_ec().message() << std::endl;
}

void Gateway::on_open(const websocketpp::connection_hdl &hdl)
{
    DEBUG("Gateway::onOpen");
    m_hdl = hdl;
}

void Gateway::on_message(const websocketpp::connection_hdl &hdl, const message_ptr &msgptr)
{
    DEBUG("Gateway::onMessage");
    Json::Value root;
    std::stringstream ss;
    ss << msgptr->get_payload();
    ss >> root;

    m_pBot->eventProc(root);
}

void Gateway::on_close(const websocketpp::connection_hdl &hdl)
{
    DEBUG("Gateway::onClose");
    m_endpoint.close(hdl, websocketpp::close::status::going_away, "");
}

void Gateway::sendPayload(const Json::Value & payload)
{
    m_endpoint.send(m_hdl,payload.toStyledString(),websocketpp::frame::opcode::text);
}
} // namespace discordpp