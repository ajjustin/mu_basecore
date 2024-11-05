Here are the unit tests for all public functions in the given file:

```
#include <Library/PerformanceLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/PcdLib.h>
#include <UnitTest/UnitTest.h>

// Unit test for GetPerformanceMeasurementProtocol function
UNIT_TEST_STATUS
EFIAPI
TestGetPerformanceMeasurementProtocol (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  EFI_STATUS Status = GetPerformanceMeasurementProtocol();
  UT_ASSERT_NOT_EFI_ERROR(Status);
  return UNIT_TEST_PASSED;
}

// Unit test for StartPerformanceMeasurementEx function
UNIT_TEST_STATUS
EFIAPI
TestStartPerformanceMeasurementEx (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  RETURN_STATUS Status = StartPerformanceMeasurementEx(NULL, "Token", "Module", 0, 0);
  UT_ASSERT_EQUAL(RETURN_SUCCESS, Status);
  return UNIT_TEST_PASSED;
}

// Unit test for EndPerformanceMeasurementEx function
UNIT_TEST_STATUS
EFIAPI
TestEndPerformanceMeasurementEx (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  RETURN_STATUS Status = EndPerformanceMeasurementEx(NULL, "Token", "Module", 0, 0);
  UT_ASSERT_EQUAL(RETURN_SUCCESS, Status);
  return UNIT_TEST_PASSED;
}

// Unit test for GetPerformanceMeasurementEx function
UNIT_TEST_STATUS
EFIAPI
TestGetPerformanceMeasurementEx (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  UINTN LogEntryKey = 0;
  CONST VOID *Handle = NULL;
  CONST CHAR8 *Token = NULL;
  CONST CHAR8 *Module = NULL;
  UINT64 StartTimeStamp = 0;
  UINT64 EndTimeStamp = 0;
  UINT32 Identifier = 0;
  UINTN NextKey = GetPerformanceMeasurementEx(LogEntryKey, &Handle, &Token, &Module, &StartTimeStamp, &EndTimeStamp, &Identifier);
  UT_ASSERT_EQUAL(0, NextKey);
  return UNIT_TEST_PASSED;
}

// Unit test for StartPerformanceMeasurement function
UNIT_TEST_STATUS
EFIAPI
TestStartPerformanceMeasurement (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  RETURN_STATUS Status = StartPerformanceMeasurement(NULL, "Token", "Module", 0);
  UT_ASSERT_EQUAL(RETURN_SUCCESS, Status);
  return UNIT_TEST_PASSED;
}

// Unit test for EndPerformanceMeasurement function
UNIT_TEST_STATUS
EFIAPI
TestEndPerformanceMeasurement (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  RETURN_STATUS Status = EndPerformanceMeasurement(NULL, "Token", "Module", 0);
  UT_ASSERT_EQUAL(RETURN_SUCCESS, Status);
  return UNIT_TEST_PASSED;
}

// Unit test for GetPerformanceMeasurement function
UNIT_TEST_STATUS
EFIAPI
TestGetPerformanceMeasurement (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  UINTN LogEntryKey = 0;
  CONST VOID *Handle = NULL;
  CONST CHAR8 *Token = NULL;
  CONST CHAR8 *Module = NULL;
  UINT64 StartTimeStamp = 0;
  UINT64 EndTimeStamp = 0;
  UINTN NextKey = GetPerformanceMeasurement(LogEntryKey, &Handle, &Token, &Module, &StartTimeStamp, &EndTimeStamp);
  UT_ASSERT_EQUAL(0, NextKey);
  return UNIT_TEST_PASSED;
}

// Unit test for PerformanceMeasurementEnabled function
UNIT_TEST_STATUS
EFIAPI
TestPerformanceMeasurementEnabled (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  BOOLEAN Enabled = PerformanceMeasurementEnabled();
  UT_ASSERT_TRUE(Enabled);
  return UNIT_TEST_PASSED;
}

// Unit test for LogPerformanceMeasurement function
UNIT_TEST_STATUS
EFIAPI
TestLogPerformanceMeasurement (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  RETURN_STATUS Status = LogPerformanceMeasurement(NULL, NULL, "String", 0, 0);
  UT_ASSERT_EQUAL(RETURN_SUCCESS, Status);
  return UNIT_TEST_PASSED;
}

// Unit test for LogPerformanceMeasurementEnabled function
UNIT_TEST_STATUS
EFIAPI
TestLogPerformanceMeasurementEnabled (
  IN UNIT_TEST_FRAMEWORK_HANDLE  Framework,
  IN UNIT_TEST_CONTEXT           Context
  )
{
  BOOLEAN Enabled = LogPerformanceMeasurementEnabled(0);
  UT_ASSERT_TRUE(Enabled);
  return UNIT_TEST_PASSED;
}

// Entry point for the unit test
EFI_STATUS
EFIAPI
PerformanceLibUnitTestMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS Status;
  UNIT_TEST_FRAMEWORK_HANDLE Framework;
  UNIT_TEST_SUITE_HANDLE Suite;

  Status = InitUnitTestFramework(&Framework, &SystemTable->ConOut, &SystemTable->StdErr);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  Status = CreateUnitTestSuite(&Suite, Framework, "PerformanceLib Unit Tests", "UEFI PerformanceLib unit tests", NULL, NULL);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  AddTestCase(Suite, "Test GetPerformanceMeasurementProtocol", "Test GetPerformanceMeasurementProtocol", TestGetPerformanceMeasurementProtocol, NULL, NULL, NULL);
  AddTestCase(Suite, "Test StartPerformanceMeasurementEx", "Test StartPerformanceMeasurementEx", TestStartPerformanceMeasurementEx, NULL, NULL, NULL);
  AddTestCase(Suite, "Test EndPerformanceMeasurementEx", "Test EndPerformanceMeasurementEx", TestEndPerformanceMeasurementEx, NULL, NULL, NULL);
  AddTestCase(Suite, "Test GetPerformanceMeasurementEx", "Test GetPerformanceMeasurementEx", TestGetPerformanceMeasurementEx, NULL, NULL, NULL);
  AddTestCase(Suite, "Test StartPerformanceMeasurement", "Test StartPerformanceMeasurement", TestStartPerformanceMeasurement, NULL, NULL, NULL);
  AddTestCase(Suite, "Test EndPerformanceMeasurement", "Test EndPerformanceMeasurement", TestEndPerformanceMeasurement, NULL, NULL, NULL);
  AddTestCase(Suite, "Test GetPerformanceMeasurement", "Test GetPerformanceMeasurement", TestGetPerformanceMeasurement, NULL, NULL, NULL);
  AddTestCase(Suite, "Test PerformanceMeasurementEnabled", "Test PerformanceMeasurementEnabled", TestPerformanceMeasurementEnabled, NULL, NULL, NULL);
  AddTestCase(Suite, "Test LogPerformanceMeasurement", "Test LogPerformanceMeasurement", TestLogPerformanceMeasurement, NULL, NULL, NULL);
  AddTestCase(Suite, "Test LogPerformanceMeasurementEnabled", "Test LogPerformanceMeasurementEnabled", TestLogPerformanceMeasurementEnabled, NULL, NULL, NULL);

  Status = RunAllTestSuites(Framework);

  FreeUnitTestFramework(Framework);

  return Status;
}
```