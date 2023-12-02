/* NYSEEEEEEEEEEEEEEEEEEEM*/

//hello

//For the movie table
#include <iostream>
#include <string>
#include <stdlib.h>

/*Drivers for SQL*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
/* cout << "Please enter the name of the movie";
    string movieName = "";
    cin >> movieName;

    cout << "You entered the movie " << movieName << endl; */

using namespace std;

int main()
{
    cout << endl;
    //cout << "Running 'SELECT 'Hello World!' »
    //AS _message'..." << endl;



    try {

    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    sql::PreparedStatement *prep_stmt;

    /* Create a connection */
    driver = get_driver_instance();
    con = driver->connect("tcp://deltona.birdnest.org:3306", "my.weaverh3", "r780t0b1");
    /* Connect to the MySQL test database */
    con->setSchema("my_weaverh3_groupProgrammingProject");

    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT Name AS _column FROM Movie");
    while (res->next()) {
        cout << "\t... MySQL replies: ";
        /* Access column data by alias or column name */
        cout << res->getString("_column") << endl;
        cout << "\t... MySQL says it again: ";
        /* Access column data by numeric offset, 1 is the first column */
        cout << res->getString(1) << endl;
    }

    string movie;
    cout << "Put 'Barney'" << endl;
    cin >> movie;

    prep_stmt = con->prepareStatement("INSERT INTO Movie (Name,YearReleased,Runtime,Description) VALUES (?, ?, ?, ?)");
    prep_stmt->setString(1,"Elmo");
    prep_stmt->setInt(2,1996);
    prep_stmt->setInt(3,1);
    prep_stmt->setString(4,"Elmo scares me sometimes");
    prep_stmt->execute();
    res = stmt->executeQuery("SELECT Name AS _column FROM Movie");
    
    while (res->next()) {
        cout << "\t... MySQL replies: ";
        /* Access column data by alias or column name */
        cout << res->getString("_column") << endl;
        cout << "\t... MySQL says it again: ";
        /* Access column data by numeric offset, 1 is the first column */
        cout << res->getString(1) << endl;
    }

    //DELETES FOR POINTERS DONT MESS W THIS!!!!!!!!!!!!:D
    delete res;
    delete stmt;
    delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    return EXIT_SUCCESS;

    return 0;
    
}