/*
 * ExampleTestSuite.cpp
 *
 *  Created on: Jun 30, 2014
 */

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#include <cppunit/extensions/TestFactoryRegistry.h>

//#include <cpptest-assert.h>
//#include <cpptest-suite.h>

//#include <cpptest-source.h>
//#include <cpptest-time.h>
//#include <cpptest-compileroutput.h>
//#include <cpptest-htmloutput.h>
//#include <cpptest-textoutput.h>

class ComplexNumberTest : public CppUnit::TestFixture  {
private:
  //Complex *m_10_1, *m_1_1, *m_11_2;
public:
  void setUp()
  {
    //m_10_1 = new Complex( 10, 1 );
    //m_1_1 = new Complex( 1, 1 );
    //m_11_2 = new Complex( 11, 2 );
  }

  void tearDown()
  {
    //delete m_10_1;
    //delete m_1_1;
    //delete m_11_2;
  }

  void testEquality()
  {
    //CPPUNIT_ASSERT( *m_10_1 == *m_10_1 );
    //CPPUNIT_ASSERT( !(*m_10_1 == *m_11_2) );
  }

  void testAddition()
  {
    //CPPUNIT_ASSERT( *m_10_1 + *m_1_1 == *m_11_2 );
  }
};


