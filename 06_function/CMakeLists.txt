cmake_minimum_required(VERSION 3.12)
project("test_function")

# 定义函数
function(func1)
    message("=== testcmakefunction ===")
endfunction()
# 调用函数
func1()
message("------------------")

#--------------------------------------------------------
function(func2 arg)
    message("arg: ${arg}")
endfunction()

func2(this_is_my_arg)
message("------------------")

#--------------------------------------------------------
function(func3)
    message("argc: ${ARGC}    argv: ${ARGV}    argn: ${ARGN}")
endfunction()

func3()
func3(arg)
func3(arg1 arg2)# 参数应该用空格分隔
func3(arg1,arg2)# 不能用','分隔参数
message("------------------")

#--------------------------------------------------------
# 类似c++的可变参数，ARGN是个list
function(func4 arg)
    message("arg: ${arg}    argn: ${ARGN}")
endfunction()

func4(the_arg other_arg1 other_arg2)
message("------------------")

#--------------------------------------------------------
function(func5)
    #--------1-----------
    #set(noValues"")
    #set(singleValues ARG_1)
    #set(multiValues ARG_2)
    #cmake_parse_arguments(
    #    PARSE_ARGV 0 the_arg
    #    "${noValues}" "${singleValues}" "${multiValues}"
    #)
    #--------1-----------
    
    # 1和2效果一样
    # the_arg就是一个前缀，也可以起别的名字
    # 0表示参数开始的位置，序号之前的参数将会被忽略
    
    #--------2-----------
    cmake_parse_arguments(
        PARSE_ARGV 0 the_arg
        "" "ARG_1" "ARG_2"
    )
    #--------2-----------
    
    # 定义了关键词，但是没有对应的值
    message("keywords missing value: ${the_arg_KEYWORDS_MISSING_VALUES}")
        
    # 不能解析的参数
    if(the_arg_UNPARSED_ARGUMENTS)
        message("UNPARSED_ARGUMENTS: ${the_arg_UNPARSED_ARGUMENTS}")
        foreach(arg_ IN LISTS the_arg_UNPARSED_ARGUMENTS)
            message("theunparsedarg: ${arg_}")
        endforeach()
    endif()
    
    # 单个参数
    if(the_arg_ARG_1)
        message("singleValues: ${the_arg_ARG_1}")
        foreach(arg_ IN LISTS the_arg_ARG_1)
            message("thesinglevalue: ${arg_}")
        endforeach()
    endif()
    
    # 多个参数
    if(the_arg_ARG_2)
        message("multiValues: ${the_arg_ARG_2}")
        foreach(arg_ IN LISTS the_arg_ARG_2)
            message("themultivalue: ${arg_}")
        endforeach()
    endif()
    
    message("-----------------------")
endfunction()

func5(xx yy "zz;123" ARG_1)        #ARG_1之前的参数被解析为UNPARSED_ARGUMENTS
func5(ARG_1 aa)                    #ARG_1之后的一个参数被解析为单参数(ARG_1对应于cmake_parse_arguments中的ARG_1)
func5(ARG_1 aa bb)                #ARG_1之后除过第一个参数被解析为UNPARSED_ARGUMENTS
func5(ARG_1 aa bb ARG_2)        #ARG_2和ARG_1都可以为空，会被解析为KEYWORDS_MISSING_VALUES
func5(ARG_1 aa ARG_2 cc dd ee)    #ARG_2之后的多个参数被解析为多参数
func5(ARG_2 x y z ARG_1 aaa)    #ARG_1和ARG_2可以打乱顺序

#--------------------------------------------------------
function(func6)
    set(prefix ARG)
    set(noValues NOV1 NOV2)
    set(singleValues ARG1)
    set(multiValues ARG2 ARG3)

    #--------1-----------
    #cmake_parse_arguments(
    #    ${prefix}
    #    "${noValues}" "${singleValues}" "${multiValues}"
    #    ${ARGN}
    #)
    #--------1-----------
    
    # 1 和 2 效果一样
    
    #--------2------------
    cmake_parse_arguments (
        PARSE_ARGV 0
        ${prefix}
        "${noValues}" "${singleValues}" "${multiValues}"
    )
    #--------2------------
    
    foreach(arg IN LISTS noValues)
        if(${prefix}_${arg})
            message("${arg} enabled")
        else()
            message("${arg} disabled")
        endif()
    endforeach()
    
    foreach(arg IN LISTS singleValues multiValues)
        message("${arg}= ${${prefix}_${arg}}")
    endforeach()
endfunction()

func6(ARG2 aa bb cc
ARG1 MyApp1
NOV1
)

message("---------------")

func6(NOV2
ARG1 MyApp2
ARG3 xx yy zz
)

message("---------------")

func6(NOV2 n1 n2
ARG1 MyApp2
ARG3 xx yy zz
)

#--------------------------------------------------------------------------------------
# 解析参数
function(MyFunction)
    # 定义参数解析的方式
    cmake_parse_arguments(
        PARSE_ARGV 0 theArgs
        "" "InArg" "OutArgs"
    )

    # 参数解析错误直接结束
    if(the_arg_UNPARSED_ARGUMENTS)
        message(FATAL_ERROR "------------- wrong of function args -------------")
    endif()

    # 单个参数
    if(theArgs_InArg)
        message("singleValues: ${theArgs_InArg}")
    endif()
    
    # 多个参数
    if(theArgs_OutArgs)
        message("multiValues: ${theArgs_OutArgs}")
    endif()

    # 获取OutArgs参数的长度
    list(LENGTH theArgs_OutArgs the_length)
    message("length of OutArgs: ${the_lenght}")

    # 如果OutArgs的参数长度等于2
    if(the_length EQUAL 2)
        message("OutArgs have two args")

        # 访问OutArgs指定位置的元素
        list(GET theArgs_OutArgs 0 _arg0)
        list(GET theArgs_OutArgs 1 _arg1)

        message("arg 0: ${_arg0}")
        message("arg 1: ${_arg1}")

    endif()

endfunction(MyFunction)

# 调用函数
MyFunction(InArg "this is in ARGS" OutArgs "out1" "out2")

#--------------------------------------------------------------------------------------
# 将结果赋值给参数
# CMake不能返回值，所以只能类似C++传入引用的方式获取函数执行结果
function(MyFunction2)
    cmake_parse_arguments(
        PARSE_ARGV 0 theArgs
        "" "InArg" "OutArgs"
    )

    if(the_arg_UNPARSED_ARGUMENTS)
        message(FATAL_ERROR "------------- wrong of function args -------------")
    endif()

    if(theArgs_InArg)
        message("singleValues: ${theArgs_InArg}")
    endif()
    
    # 将结果赋值给参数
    if(theArgs_OutArgs)
        set(${theArgs_OutArgs} "function output" PARENT_SCOPE)
    endif()

endfunction(MyFunction2)

# 调用函数
MyFunction2(InArg "function 2" OutArgs OUT_ARG)
message("this is function return value: ${OUT_ARG}")