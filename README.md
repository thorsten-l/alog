# ALOG for Arduino

## A quite simple Arduino logging library based on the C preprocessor.

The purpose of this logging library is to leave no executable code into your programm if you complete disabling it. All logging info will be created via `Serial.printf(...)`

```text
build_flags = -UALOG_LEVEL
```

### Enabling logging levels

```text
build_flags = -DALOG_LEVEL=[1-5]
```

#### 1 ERROR log level

`ALOG_E( "ERROR number: %d", errorno );`

#### 2 WARNING log level

`ALOG_W( "WARNING number: %d", warn );`

#### 3 WARNING log level

`ALOG_I( "INFO: %s", info_message );`

#### 4 DEBUG log level

`ALOG_D( "DEBUG: %s : %d", key, value  );`

`ALOG_D_HEAP();` Shortcut prints current heap size

#### 5 VERBOSE log level

`ALOG_V( "VERBOSE: the password is %s", password );`
