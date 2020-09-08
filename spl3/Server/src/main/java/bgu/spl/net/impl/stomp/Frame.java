package bgu.spl.net.impl.stomp;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Frame {
    private String stompCommand;
    private List<Header> headers;
    private String frameBody;

    public Frame(String stompCommand, List headers, String frameBody) {
        this.stompCommand = stompCommand;
        this.headers = headers;
        this.frameBody = frameBody;
    }

    public List<Header> getHeaders() {
        return headers;
    }

    public String getFrameBody() {
        return frameBody;
    }

    public String getStompCommand() {
        return stompCommand;
    }

    public void addHeader(String headerName, String headerValue) {
        headers.add(new Header(headerName, headerValue));
    }

    public String makeEncodeString() {
        String ret = stompCommand;
        for (Header header : headers)
            ret += "\n" + header.getName() + ":" + header.getValue();
        ret += "\n\n" + frameBody;
        return ret;
    }

    public static Frame makeDecodedFrame(String frameString) {
        if (frameString == null) {
            return null;
        }
        String stompCommand = "";
        List<Header> headersList = new LinkedList<>();
        String frameBody = "";

        Scanner scanner = new Scanner(frameString);
        if (scanner.hasNextLine())
            stompCommand = scanner.nextLine();
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            if (line.equals(""))
                break;
            String[] parts = line.split(":");
            headersList.add(new Header(parts[0], parts[1]));
        }
        if (scanner.hasNextLine())
            frameBody = scanner.nextLine();
        scanner.close();

        return new Frame(stompCommand, headersList, frameBody);
    }

    public void removeHeader(String topicId) {
        for (Header header : headers) {
            if (header.getName() == topicId) {
                headers.remove(header);
                break;
            }
        }
    }
}
