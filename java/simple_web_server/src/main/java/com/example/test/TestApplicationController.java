package com.example.test;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class TestApplicationController {

    @RequestMapping("/")  // Set current method as root
    public String test() {
        return "Hello World";
    }
}
