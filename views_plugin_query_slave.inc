<?php
// $Id$

/**
 * @file views_plugin_query_slave.inc
 * Defines the default query object which builds SQL to execute using the slave
 * database API within Pressflow.
 */

/**
 * Extension of views_plugin_query_default to query a slave db if it exists. The
 * slave database is only queried against if there is caching in place on the
 * view.
 */
class views_plugin_query_slave extends views_plugin_query_default{
  /**
   * Whether or not this view is safe to be run against the Slave database.
   *
   * @var boolean
   */
  protected $slave_safe = TRUE;

  /**
   * Wrapper method for db_query().
   *
   * @param $query
   *   A string containing an SQL query.
   * @param $args
   *   An array containing the query arguments.
   * @return
   *   A database query result resource, or FALSE if the query was not executed
   *   correctly.
   */
  function db_query($query, $args = array()) {
    $fnc = $this->slave_safe ? 'db_query_slave' : 'db_query';
    return $fnc($query, $args);
  }

  /**
   * Wrapper method for db_query_range().
   *
   * @param $query
   *   A string containing an SQL query.
   * @param $from
   *   The first result row to return.
   * @param $count
   *   The maximum number of result rows to return.
   * @param $args
   *   An array containing the query arguments.
   * @return
   *   A database query result resource, or FALSE if the query was not executed
   *   correctly.
   */
  function db_query_range($query, $from, $count, $args = array()) {
    $fnc = $this->slave_safe ? 'db_query_range_slave' : 'db_query_range';
    return $fnc($query, $from, $count, $args);
  }
}
