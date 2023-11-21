package com.example.test;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class TestApplicationController {

    @RequestMapping("/")  // Set current method as root
    public String response_root() {
        return "Hello World \nThis is the root page";
    }

    @RequestMapping("/hi")  // Set current method as root
    public String hello(@RequestParam(value = "name", defaultValue = "User") String name) {
      return String.format("Hi %s! \nThis is the hi page", name);
    }
}
